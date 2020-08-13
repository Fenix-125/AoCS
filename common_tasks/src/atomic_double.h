//
// Created by fenix on 5/11/20.
//

#ifndef COUNT_NUMBER_OF_ALL_WORDS_ATOMIC_DOUBLE_H
#define COUNT_NUMBER_OF_ALL_WORDS_ATOMIC_DOUBLE_H


#include <mutex>

class atomic_double {
    double val;
    std::mutex mux{};

public:
    explicit atomic_double(double val) : val(val) {}
    ~atomic_double() = default;

    static bool is_lock_free() {return false;}

    void store(double new_val) {
        std::lock_guard<std::mutex> lg{mux};
        val = new_val;
    }

    double store() {
        std::lock_guard<std::mutex> lg{mux};
        return val;
    }

    double fetch_add(double operand) {
        std::lock_guard<std::mutex> lg{mux};
        return (val += operand);
    }
    double fetch_sub(double operand) {
        std::lock_guard<std::mutex> lg{mux};
        return (val -= operand);
    }
};


#endif //COUNT_NUMBER_OF_ALL_WORDS_ATOMIC_DOUBLE_H
