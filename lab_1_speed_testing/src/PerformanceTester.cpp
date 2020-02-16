//
// Created by fenix on 2/12/20.
//

#include "../include/PerformanceTester.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <chrono>
#include <atomic>


// ######################### HELPER FUNCTIONS #########################
static inline std::chrono::high_resolution_clock::time_point get_current_time_fenced() {
    std::atomic_thread_fence(std::memory_order_seq_cst);
    auto res_time = std::chrono::high_resolution_clock::now();
    std::atomic_thread_fence(std::memory_order_seq_cst);
    return res_time;
}

// source: https://web.archive.org/web/20180314195042/http://cpp.indi.frih.net/blog/2014/09/how-to-read-an-entire-file-into-memory-in-cpp/
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


// #########################   CLASS METHODS  #########################
PerformanceTester::PerformanceTester(const std::string &f_name, AbstractCastDoubleFunction *subject)
        : subject(subject), data(nullptr) { load_data(f_name); }

PerformanceTester::PerformanceTester(const std::vector<double> *data_set, AbstractCastDoubleFunction *subject)
        : data(data_set), subject(subject) {}

PerformanceTester::PerformanceTester(const PerformanceTester &other)
        : subject(other.subject), data(new std::vector<double>{*other.data}) {}

PerformanceTester::~PerformanceTester() { delete data; }

PerformanceTester &PerformanceTester::operator=(const PerformanceTester &arg) {
    if (&arg == this) { return *this; }
    PerformanceTester temp{arg};
    temp.swap(*this);
    return *this;
}

//                                   default 'times' = 1
void PerformanceTester::run_speed_test(long long times) {
    auto start = get_current_time_fenced();

    for (int i = 0; i < times; ++i) {
        for (auto &elem : *data) {
            subject->cast(elem);
        }
    }

    auto finish = get_current_time_fenced();
    update_time_record(start, finish, times);
}

void PerformanceTester::calculate_cast_result() {
    char_count = 0;
    for (auto &elem : *data) {
        char_count += subject->cast(elem).length();
    }
    avg_num_length = (double) char_count / data->size();
}

void PerformanceTester::print_data() const {
    for (auto &elem : *data) {
        printf("%.14lf\n", elem);
    }
}

// default 'times' value is 1
void PerformanceTester::update_time_record(std::chrono::high_resolution_clock::time_point start,
                                           std::chrono::high_resolution_clock::time_point finish,
                                           long long times) {
    sec = std::min(std::chrono::duration_cast<std::chrono::seconds>(finish - start).count() / times, sec);
    m_sec = std::min(std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count() / times, m_sec);
    u_sec = std::min(std::chrono::duration_cast<std::chrono::microseconds>(finish - start).count() / times, u_sec);
}

void PerformanceTester::swap(PerformanceTester &other) {
    std::swap(data, other.data);
    std::swap(subject, other.subject);
}

void PerformanceTester::load_data(const std::string &f_name) {
    auto *tmp_data = new std::vector<double>();
    std::ifstream file(f_name);
    std::istringstream str_stream(read_stream_into_string(file));

    double tmp_num;
    while (str_stream >> tmp_num) {
        tmp_data->push_back(tmp_num);
    }

    file.close();
    data = tmp_data;
}
