#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <memory>
#include <future>
#include <queue>
#include <condition_variable>

template<typename T>
class ThreadSafeQueue {
private:
    mutable std::mutex mut;
    std::queue<std::shared_ptr<T>> data_queue;
    std::condition_variable data_cond;
public:
    ThreadSafeQueue() {}
    void wait_and_pop(T& value) {
        std::unique_lock<std::mutex> lk(mut);
        data_cond.wait(lk, [this]{return !data_queue.empty();});
        value = std::move(*data_queue.front());
        data_queue.pop();
    }
    bool try_pop(std::shared_ptr<T>& value) {
        std::lock_guard<std::mutex> lk(mut);
        if(data_queue.empty()) return false;
        value = data_queue.front();
        data_queue.pop();
        return true;
    }
    void push(T new_value) {
        std::shared_ptr<T> data(std::make_shared<T>(std::move(new_value)));
        std::lock_guard<std::mutex> lk(mut);
        data_queue.push(data);
        data_cond.notify_one();
    }
};

// Hash 2227
// Hash 2661
// Hash 8249
// Hash 4250
// Hash 4033
// Hash 1288
// Hash 2132
// Hash 2438
// Hash 9493
// Hash 6545
// Hash 6637
// Hash 9783
// Hash 9606
// Hash 7051
// Hash 1635
// Hash 8932
// Hash 5928
// Hash 1931
// Hash 7528
// Hash 4375
// Hash 2913
// Hash 1838
// Hash 4979
// Hash 3554
// Hash 8172
// Hash 5573
// Hash 8421
// Hash 9972
// Hash 8962
// Hash 8813
// Hash 9270
// Hash 3220
// Hash 3596
// Hash 6956
// Hash 5593
// Hash 4949
// Hash 6011
// Hash 8043
// Hash 6033
// Hash 1000
// Hash 2844
// Hash 1022
// Hash 4553
// Hash 2129
// Hash 1641