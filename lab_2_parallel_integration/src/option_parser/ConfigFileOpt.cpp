//
// Created by fenix on 2/25/20.
//

#include "../../include/option_parser/ConfigFileOpt.h"
#include "../../include/exception/OptionsParseException.h"

#include <boost/filesystem.hpp>
#include <cassert>
#include <iostream>

namespace po = boost::program_options;

ConfigFileOpt::ConfigFileOpt() {
    _init_opt_description();
}

ConfigFileOpt::ConfigFileOpt(const ConfigFileOpt &other)
        : abs_pars(other.abs_pars), rel_pres(other.rel_pres), exp_sol(other.exp_sol), flow_num(other.flow_num),
          x(std::pair<double, double>{other.x.first, other.x.second}),
          y(std::pair<double, double>{other.y.first, other.y.second}),
          opt_conf(po::options_description{other.opt_conf}),
          var_map(po::variables_map{other.var_map}) {}


ConfigFileOpt &ConfigFileOpt::operator=(const ConfigFileOpt &arg) {
    if (&arg == this) { return *this; }
    ConfigFileOpt temp{arg};
    return *this;
}

void ConfigFileOpt::parse(std::string &file_name) {
    try {
        std::ifstream conf_file(_assert_file_exist(file_name));

        po::store(po::parse_config_file(conf_file, opt_conf), var_map);
        po::notify(var_map);
    } catch (std::exception &E) {
        std::cerr << E.what() << std::endl;
        throw OptionsParseException();
    }
    _assert_valid_opt_vals();
}

void ConfigFileOpt::_init_opt_description() {
    opt_conf.add_options()
            ("abs_pres", po::value<double>(&abs_pars), "absolute precision")
            ("rel_pres", po::value<double>(&rel_pres), "relative precision")
            ("flow_num", po::value<size_t>(&flow_num), "parallel execution flows number")
            ("exp_sol", po::value<double>(&exp_sol), "expected solution")
            ("x.start", po::value<double>(&(x.first)), "start of the x region")
            ("x.end", po::value<double>(&(x.second)), "end of the x region")
            ("y.start", po::value<double>(&(y.first)), "start of the y region")
            ("y.end", po::value<double>(&(y.second)), "end of the y region");
}

std::string ConfigFileOpt::_assert_file_exist(std::string &f_name) {
    if (!boost::filesystem::exists(f_name)) {
        throw std::invalid_argument("File " + f_name + " not found!");
    }
    return f_name;
}

void ConfigFileOpt::_assert_valid_opt_vals() const {
    assert(x.first < x.second && "Invalid integration range for x");
    assert(y.first < y.second && "Invalid integration range for y");
}
