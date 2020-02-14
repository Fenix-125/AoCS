//
// Created by fenix on 2/12/20.
//

#include "../include/PerformanceTester.h"
#include <fstream>
#include <iostream>
#include <sstream>


PerformanceTester::PerformanceTester(std::string f_name, const AbstractCastDoubleFunction &subject) : subject(subject) {
    load_data(f_name);
}

PerformanceTester::PerformanceTester(const AbstractCastDoubleFunction &subject)
        : subject(subject), data(nullptr) {}

PerformanceTester::PerformanceTester(const PerformanceTester &other) : subject(other.subject), data(nullptr) {
}

PerformanceTester::~PerformanceTester() {
    delete data;
}

void PerformanceTester::swap(PerformanceTester &other) {
    std::swap(data, other.data);
}

PerformanceTester &PerformanceTester::operator=(const PerformanceTester &arg) {
    if (&arg == this) { return *this; }
    PerformanceTester temp{arg};
    temp.swap(*this);
    return *this;
}

// default 'times' value is 1
void PerformanceTester::test(int times) {
//    TODO: implement test call and result update

}

template<typename CharT, typename Traits,
        typename Allocator = std::allocator<CharT>>
static auto read_stream_into_string(std::basic_istream<CharT, Traits> &in, Allocator alloc = {}) {
    std::basic_ostringstream<CharT, Traits, Allocator>
            ss(std::basic_string<CharT, Traits, Allocator>(std::move(alloc)));

    if (!(ss << in.rdbuf())) {
        throw std::ios_base::failure{"error"};
    }
    return ss.str();
}

void PerformanceTester::load_data(const std::string &f_name) {
    if (data == nullptr) {
        data = new std::vector<double>();
    } else {
        data->clear();
    }

    std::ifstream file(f_name);
    std::istringstream str_stream(read_stream_into_string(file));

    double tmp_num;
    while (str_stream >> tmp_num) {
        data->push_back(tmp_num);
    }
    file.close();
}

void PerformanceTester::update_time_record(std::chrono::duration_values<std::chrono::seconds> n_sec) {
    sec = n_sec;
}

void PerformanceTester::print_data() {
    for (auto &elem : *data) {
        printf("%.14lf\n", elem);
    }
}

void PerformanceTester::update_time_record(std::chrono::duration_values<std::chrono::milliseconds> nm_sec) {
    m_sec = nm_sec;
}

void PerformanceTester::update_time_record(std::chrono::duration_values<std::chrono::microseconds> nu_sec) {
    u_sec = nu_sec;
}
