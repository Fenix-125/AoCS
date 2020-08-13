//
// Created by fenix on 5/10/20.
//

#include <boost/thread/concurrent_queues/deque_adaptor.hpp>
#include <atomic>
#include <functional>
#include <thread>
#include <deque>

class thread_pool {
    std::atomic_bool done;
    boost::deque_adaptor<std::deque<std::function<void()>>> work_queue{};
    std::vector<std::thread> threads;

    void worker_thread() {
        while (!done) {
            std::function<void()> task;
            if (work_queue.try_pull_front(task) == boost::queue_op_status::success) {
                task();
            } else {
                std::this_thread::yield();
            }
        }
    }

public:
    thread_pool() : done{false} {
        unsigned const thread_count =
                std::thread::hardware_concurrency();
        try {
            for (unsigned i = 0; i < thread_count; ++i)
                threads.emplace_back(&thread_pool::worker_thread, this);
        } catch (...) {
            done = true;
            throw;
        }
    }

    ~thread_pool() {
        for (auto &thread : threads)
            thread.join();
    }

    template<typename FunctionType>
    void submit(FunctionType f) {
        work_queue.push_back(std::function<void()>(f));
    }
};