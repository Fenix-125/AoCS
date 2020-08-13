//
// Created by fenix on 5/9/20.
//

#include <mutex>

namespace ucu {
    class my_unique_lock;
    struct defer_lock;
}

struct ucu::defer_lock : std::defer_lock_t {};

class ucu::my_unique_lock {
    std::mutex* mux;
    size_t owned = 0;

public:
    explicit my_unique_lock(std::mutex &mux) : mux(&mux){ mux.lock(); ++owned;}

    my_unique_lock(std::mutex &mux, defer_lock) : mux(&mux) {}

    my_unique_lock() = delete;

    my_unique_lock(const my_unique_lock &my_ulock) = delete;

    my_unique_lock operator=(const my_unique_lock &my_ulock) = delete;

    void lock() {

    }

    void unlock() {

    }

    bool try_lock() {
        return false;
    }
};