#include <iostream>
#include "include/option_parser/ConfigFileOpt.h"
//#include <thread>
//#include <vector>

//void f(double *c);
void test_conf_opts();

int main() {
    test_conf_opts();
    return 0;

//    std::vector<std::thread> v(43);
//    std::vector<double> v_res(43);
//    for (int i = 0; i < 43; ++i) {
//        v.emplace_back(std::thread{f, &(v_res[43])});
//    }
//    for (int i = 0; i < 43; ++i) {
//        v[i].join();
//    }
//    double f_res = 0.0;
//    for (int i = 0; i < 43; ++i) {
//        f_res += v_res[i];
//    }

}

void test_conf_opts() {
    ConfigFileOpt cf{};
    std::string file_name = "../execution.ini";
    cf.parse(file_name);
    std::cout << "get_x " << cf.get_x().first << " " << cf.get_x().second << std::endl;
    std::cout << "get_y " << cf.get_y().first << " " << cf.get_y().second << std::endl;
    std::cout << "get_abs_pars " << cf.get_abs_pars() << std::endl;
    std::cout << "get_rel_pres " << cf.get_rel_pres() << std::endl;
    std::cout << "get_flow_num " << cf.get_flow_num() << std::endl;
    std::cout << "get_exp_sol " << cf.get_exp_sol() << std::endl;
}
