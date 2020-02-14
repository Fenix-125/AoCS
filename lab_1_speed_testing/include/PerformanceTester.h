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
    PerformanceTester(std::string f_name, const AbstractCastDoubleFunction &subject);

    PerformanceTester(const AbstractCastDoubleFunction &subject);

    PerformanceTester(const PerformanceTester &other);

    ~PerformanceTester();

    PerformanceTester &operator=(const PerformanceTester &arg);

    void load_data(const std::string &f_name);

    void test(int times = 1);

    void print_data();

private:
    const AbstractCastDoubleFunction &subject;
    std::vector<double> *data{};
    std::chrono::duration_values<std::chrono::seconds> sec;
    std::chrono::duration_values<std::chrono::milliseconds> m_sec;
    std::chrono::duration_values<std::chrono::microseconds> u_sec;

    void swap(PerformanceTester &other);

    void update_time_record(std::chrono::duration_values<std::chrono::seconds> n_sec);

    void update_time_record(std::chrono::duration_values<std::chrono::milliseconds> nm_sec);

    void update_time_record(std::chrono::duration_values<std::chrono::microseconds> nu_sec);
};


#endif //LAB_1_SPEED_TESTING_PERFORMANCETESTER_H
