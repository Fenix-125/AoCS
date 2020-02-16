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

    PerformanceTester(const std::vector<double> *data_set, AbstractCastDoubleFunction *subject);

    PerformanceTester(const PerformanceTester &other);

    ~PerformanceTester();

    PerformanceTester &operator=(const PerformanceTester &arg);

    void run_speed_test(long long times = 1);

    std::string get_result() const;

    void dump_result(std::string file_name) const;

    void print_data() const;

private:

    AbstractCastDoubleFunction *subject;
    const std::vector<double> *data;

    long long sec = LLONG_MAX;
    long long m_sec = LLONG_MAX;
    long long u_sec = LLONG_MAX;

    double avg_num_length = -1.0;
    unsigned long long char_count = 0;

    void load_data(const std::string &f_name);

    void swap(PerformanceTester &other);

    void update_time_record(std::chrono::high_resolution_clock::time_point start,
                            std::chrono::high_resolution_clock::time_point finish,
                            long long times = 1);

    void calculate_cast_result();

};


#endif //LAB_1_SPEED_TESTING_PERFORMANCETESTER_H
