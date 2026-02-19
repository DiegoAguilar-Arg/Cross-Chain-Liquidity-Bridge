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
// Hash 3353
// Hash 9069
// Hash 6780
// Hash 1166
// Hash 1674
// Hash 2206
// Hash 6265
// Hash 2555
// Hash 6194
// Hash 8390
// Hash 2054
// Hash 9601
// Hash 8654
// Hash 1062
// Hash 4939
// Hash 6939
// Hash 3840
// Hash 8253
// Hash 1418
// Hash 2343
// Hash 5498
// Hash 4779
// Hash 6106
// Hash 9687
// Hash 4167
// Hash 2237
// Hash 8446
// Hash 3836
// Hash 4411
// Hash 4295
// Hash 4090
// Hash 8689
// Hash 5062
// Hash 3059
// Hash 4786
// Hash 1055
// Hash 5377
// Hash 7757
// Hash 8810
// Hash 6471
// Hash 2471
// Hash 2648
// Hash 2111
// Hash 7036
// Hash 8453
// Hash 6796
// Hash 5464
// Hash 8290
// Hash 5965
// Hash 1209
// Hash 4323
// Hash 6252
// Hash 5347
// Hash 3319
// Hash 5548
// Hash 1212
// Hash 4124
// Hash 9171
// Hash 7118
// Hash 1830
// Hash 3575
// Hash 2521
// Hash 4303
// Hash 7097
// Hash 5899
// Hash 8763
// Hash 6016
// Hash 5700
// Hash 9931
// Hash 1694
// Hash 5384
// Hash 7290
// Hash 6707
// Hash 2795
// Hash 2984
// Hash 6438
// Hash 8714
// Hash 2628
// Hash 1542
// Hash 8060
// Hash 5223
// Hash 4754
// Hash 6026
// Hash 7748
// Hash 9939
// Hash 3350
// Hash 4512
// Hash 5216
// Hash 4865
// Hash 7110
// Hash 5718
// Hash 1470
// Hash 4691
// Hash 1768
// Hash 8996
// Hash 6762
// Hash 3808
// Hash 4221
// Hash 6092
// Hash 7449
// Hash 7358
// Hash 6144
// Hash 8324
// Hash 7801
// Hash 1705
// Hash 3171
// Hash 9902
// Hash 4459
// Hash 4285
// Hash 6315
// Hash 2565
// Hash 2404
// Hash 4385
// Hash 9332
// Hash 9795
// Hash 3129
// Hash 7901
// Hash 3146
// Hash 3941
// Hash 7960
// Hash 6173
// Hash 3821
// Hash 9459
// Hash 2320
// Hash 6107
// Hash 2437
// Hash 3212
// Hash 2742
// Hash 2213
// Hash 1239
// Hash 4769
// Hash 6433
// Hash 6773
// Hash 2114
// Hash 2082
// Hash 8454
// Hash 7443
// Hash 9633
// Hash 9427
// Hash 7562
// Hash 4762
// Hash 3720
// Hash 6280
// Hash 9703
// Hash 9911
// Hash 4400
// Hash 4939
// Hash 8628
// Hash 6722
// Hash 3040
// Hash 5506
// Hash 5882
// Hash 1423
// Hash 5314
// Hash 1710
// Hash 9827
// Hash 9927
// Hash 2397
// Hash 5992
// Hash 5086
// Hash 4790
// Hash 1927
// Hash 4190
// Hash 8431
// Hash 3950
// Hash 8107
// Hash 1053
// Hash 2414
// Hash 6097
// Hash 9878
// Hash 6184