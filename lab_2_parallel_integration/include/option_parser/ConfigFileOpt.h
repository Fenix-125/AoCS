//
// Created by fenix on 2/25/20.
//

#ifndef LAB_2_PARALLEL_INTEGRATION_CONFIGFILEOPT_H
#define LAB_2_PARALLEL_INTEGRATION_CONFIGFILEOPT_H


#include <string>
#include <boost/program_options.hpp>


class ConfigFileOpt {
public:
    ConfigFileOpt();

    ~ConfigFileOpt() = default;

    ConfigFileOpt(const ConfigFileOpt &other);

    ConfigFileOpt &operator=(const ConfigFileOpt &arg);

    void parse(std::string &file_name);

    double get_abs_pars() { return abs_pars; }

    double get_rel_pres() { return rel_pres; }

    double get_exp_sol() { return exp_sol; }

    size_t get_flow_num() { return flow_num; }

    std::pair<double, double> get_x() { return x; }

    std::pair<double, double> get_y() { return y; }

private:
    void _init_opt_description();

    static std::string _assert_file_exist(std::string &f_name);

    void _assert_valid_opt_vals() const;

    double abs_pars = 0.0, rel_pres = 0.0, exp_sol = 0.0;
    size_t flow_num = 1;
    std::pair<double, double> x{0.0, 0.0};
    std::pair<double, double> y{0.0, 0.0};

    boost::program_options::options_description opt_conf{"Config File Options"};
    boost::program_options::variables_map var_map{};
};


#endif //LAB_2_PARALLEL_INTEGRATION_CONFIGFILEOPT_H
