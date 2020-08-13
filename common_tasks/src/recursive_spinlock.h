//
// Created by fenix on 5/11/20.
//

#ifndef COUNT_NUMBER_OF_ALL_WORDS_RECURSIVE_SPINLOCK_H
#define COUNT_NUMBER_OF_ALL_WORDS_RECURSIVE_SPINLOCK_H

#include <atomic>
#include <thread>
#include <cassert>

class recursive_spinlock_t {
    std::atomic_flag lock_flag{};
    int64_t recursive_counter = 0;
    std::atomic<std::thread::id> owner_thread_id{std::thread::id{}};
public :
    recursive_spinlock_t() {
        lock_flag.clear();
    }

    bool try_lock() {
        if (!lock_flag.test_and_set(std::memory_order_acquire)) {
            owner_thread_id.store(std::this_thread::get_id(),
                                  std::memory_order_release);
        } else {
            if (owner_thread_id.load(std::memory_order_acquire) !=
                std::this_thread::get_id())
                return false;
        }
        ++recursive_counter;
        return true;
    }

    void lock() {
        for (volatile size_t i = 0; !try_lock(); ++i)
            if (i % 1000 == 0)
                std::this_thread::yield();
    }

    void unlock() {
        assert(owner_thread_id.load(std::memory_order_acquire) ==
               std::this_thread::get_id());
        assert(recursive_counter > 0);
        if (--recursive_counter == 0) {
            owner_thread_id.store(std::thread::id{},
                                  std::memory_order_release);
            lock_flag.clear(std::memory_order_release);
        }
    }
};


#endif //COUNT_NUMBER_OF_ALL_WORDS_RECURSIVE_SPINLOCK_H
