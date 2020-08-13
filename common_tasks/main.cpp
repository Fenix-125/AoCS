//
// Created by fenix on 5/9/20.
//
#include "./src/my_async.h"

#include <mutex>
#include <condition_variable>

class thread_barrier {
private:
    std::mutex m{};
    std::condition_variable reset_signal{};
    std::condition_variable release_signal{};
    size_t threads;
    size_t waiting = 0;
    bool restart = false;

    explicit thread_barrier(size_t nthreads) : threads{nthreads} {};

public:
    void sync() {
        {
            std::unique_lock<std::mutex> lk(m);
            reset_signal.wait(lk, [this]() { return !restart; });
            if (++waiting == threads) {
                restart = true;
                --waiting;
                release_signal.notify_all();
            } else {
                release_signal.wait(lk, [this]() { return restart; });
                if (--waiting == 0) {
                    restart = false;
                }
            }
        }
        reset_signal.notify_all();
    }
};

#include <mutex>
#include <condition_variable>
#include <deque>

template<typename T>
class queue {
    std::deque<T> q{};
    std::mutex m{};
    std::condition_variable cv{};

public:
    queue() = default;

    ~queue() = default;

    void push(T element) {
        {
            std::unique_lock<std::mutex> ul{m};
            q.push_back(element);
        }
        cv.notify_one();
    }

    T pop() {
        std::unique_lock<std::mutex> ul{m};
        cv.wait(ul, [this] { return !q.empty(); });
        auto res = q.front();
        q.pop_front();
        return res;
    }

    bool empty() {
        return q.empty();
    }

    size_t size() {
        std::unique_lock<std::mutex> ul{m};
        return q.size;
    }
};


#include <mutex>
#include <condition_variable>

class barrier {
private:
    std::mutex m;
    std::condition_variable cv;
    size_t threshold;
    size_t thread_count;
    size_t iteration; // щоб відрізняти чи це з тої самої групи
public:
    explicit barrier(size_t nthreads) : threshold(nthreads), thread_count(nthreads), iteration(0) {};

    void wait() {
        std::unique_lock<std::mutex> lk{m};
        auto current_iter = iteration;
        if (!--thread_count) { // Відпускаємо і робимо ресет
            iteration++;
            thread_count = threshold;
            cv.notify_all();
        } else {
            cv.wait(lk, [this, &current_iter] { return current_iter != iteration; });
        }
    }
};


int main() {
    std::cout << "/////////////// Test Async /////////////" << std::endl;
    std::future<int> res = my_async(policies::async{}, test_func, 11, 76.9);
    std::cout << "Res " << res.get() << std::endl;

    std::cout << "///////////// Finish Tests /////////////" << std::endl;
    return 0;
}
