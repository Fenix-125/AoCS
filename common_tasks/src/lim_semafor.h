//
// Created by fenix on 5/10/20.
//

#include <limits>
#include <condition_variable>

class lim_semafor {
    size_t count;
    const size_t max_val = std::numeric_limits<size_t>::max();
    std::mutex mux;
    std::condition_variable inc_i{}, decr_i{};

public:
    lim_semafor() = delete;

    explicit lim_semafor(size_t init_val) : count(init_val) {}

    explicit lim_semafor(size_t init_val, size_t max_val)
            : count(init_val), max_val(max_val) {}

    // decrements the internal counter or blocks until it can
    void acquire() {
        {
            std::unique_lock<std::mutex> lg{mux};
            inc_i.wait(lg, [this]() { return count > 0; });
            count -= 1;
        }
        decr_i.notify_one();
    }

    // increments the internal counter and unblocks acquirers
    void release() {
        {
            std::unique_lock<std::mutex> lg{mux};
            decr_i.wait(lg, [this]() { return count < max_val; });
            count += 1;
        }
        inc_i.notify_one();
    }
};