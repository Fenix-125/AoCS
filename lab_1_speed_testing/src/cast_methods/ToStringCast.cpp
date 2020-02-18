//
// Created by fenix on 2/16/20.
//

#include "../../include/cast_methods/ToStringCast.h"

std::string ToStringCast::cast(double value) {
    // inlined and modified to_string(double) function
    const int __n = __gnu_cxx::__numeric_traits<double>::__max_exponent10 + 20;
    return __gnu_cxx::__to_xstring<std::string>(&std::vsnprintf, static_cast<size_t>(__n), "%.14f", value);
}

std::string ToStringCast::get_description() const {
    return "Casting double to string using default 'to_string' function.";
}

std::string ToStringCast::get_name() const {
    return "ToStringCast";
}
