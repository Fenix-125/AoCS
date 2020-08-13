//
// Created by fenix on 5/10/20.
//
#include <future>
#include <iostream>

namespace policies {
    struct async {
    };
    struct linear {
    };
};

int test_func(int a, double b) {
    std::cout << "Int: " << a << std::endl;
    std::cout << "Double: " << b << std::endl;
    std::this_thread::sleep_for(std::chrono::operator ""s(5));
    return 125;
}


std::future<int> my_async(policies::async, int (func)(int, double), int a, double b) {
    std::promise<int> promise{};
    std::future<int> res = promise.get_future();
    std::thread{
            [](int (func)(int, double), int a, double b, std::promise<int> &&promise) {
                promise.set_value(func(a, b));
            },
            func, a, b, std::move(promise)}.detach();
    return res;
}


std::future<int> my_async(policies::linear, int (func)(int, double), int a, double b) {
    std::promise<int> promise{};
    std::future<int> res = promise.get_future();
    promise.set_value(func(a, b));
    return std::packaged_task<int (*)(int, double)>{};
    return res;
}
