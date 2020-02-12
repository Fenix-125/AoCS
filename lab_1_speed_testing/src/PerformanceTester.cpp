//
// Created by fenix on 2/12/20.
//

#include "../include/PerformanceTester.h"

PerformanceTester::PerformanceTester(std::string f_name, const AbstractCastDoubleFunction *subject)
        : subject(subject), data(load_data(f_name)) {}

PerformanceTester::PerformanceTester(const std::vector<double> *data, const AbstractCastDoubleFunction *subject)
        : data(data), subject(subject) {}


// default 'times' value is 1
void PerformanceTester::test(int times) {
//    TODO: implement test call and result update
}

std::vector<double> *PerformanceTester::load_data(std::string f_name) {
//    TODO: implement read from file
    return new std::vector<double>();
}
