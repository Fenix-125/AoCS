//
// Created by fenix on 2/12/20.
//

#ifndef LAB_1_SPEED_TESTING_PERFORMANCETESTER_H
#define LAB_1_SPEED_TESTING_PERFORMANCETESTER_H


#include <string>
#include <vector>
#include <chrono>
#include <climits>
#include "cast_methods/AbstractCastDoubleFunction.h"


class PerformanceTester {

public:
    PerformanceTester(const std::string &f_name, AbstractCastDoubleFunction *subject);

    PerformanceTester(AbstractCastDoubleFunction *subject);

    PerformanceTester(const PerformanceTester &other);

    ~PerformanceTester();

    PerformanceTester &operator=(const PerformanceTester &arg);

    void load_data(const std::string &f_name);

    void test(long long times = 1);

    void print_data();

private:
    AbstractCastDoubleFunction *subject;
    std::vector<double> *data{};
    long long sec = LLONG_MAX;
    long long m_sec = LLONG_MAX;
    long long u_sec = LLONG_MAX;

    void swap(PerformanceTester &other);

    void update_time_record(std::chrono::high_resolution_clock::time_point start,
                            std::chrono::high_resolution_clock::time_point finish,
                            long long times = 1);

};


#endif //LAB_1_SPEED_TESTING_PERFORMANCETESTER_H
