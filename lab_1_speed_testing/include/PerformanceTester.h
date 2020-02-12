//
// Created by fenix on 2/12/20.
//

#ifndef LAB_1_SPEED_TESTING_PERFORMANCETESTER_H
#define LAB_1_SPEED_TESTING_PERFORMANCETESTER_H


#include <string>
#include <vector>
#include <chrono>
#include "cast_methods/AbstractCastDoubleFunction.h"


class PerformanceTester {

public:
    PerformanceTester(std::string f_name, const AbstractCastDoubleFunction *subject);

    PerformanceTester(const std::vector<double> *data, const AbstractCastDoubleFunction *subject);

    void test(int times = 1);

private:
    const AbstractCastDoubleFunction *subject;
    const std::vector<double> *data;
    std::chrono::duration_values<std::chrono::seconds> sec;
    std::chrono::duration_values<std::chrono::milliseconds> m_sec;
    std::chrono::duration_values<std::chrono::microseconds> u_sec;

private:
    static std::vector<double> *load_data(std::string f_name);

    void update_time_record(/* TODO: diside vhich parameters consider use generic */);
};


#endif //LAB_1_SPEED_TESTING_PERFORMANCETESTER_H
