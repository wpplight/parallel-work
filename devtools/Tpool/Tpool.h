#pragma once
#include <vector>
#include <thread>
#include <atomic>
class Tpool{
    public:
    explicit Tpool(int num);

    private:
    //保留池
    std::vector<std::thread> _pool;
    //池尺寸
    int _len;
    //活动线程数
    std::atomic<int> _activity_threads;
    void init_pool();
    void thread_run();
};