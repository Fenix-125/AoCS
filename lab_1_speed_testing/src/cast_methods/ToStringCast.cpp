//
// Created by fenix on 2/16/20.
//

#include "../../include/cast_methods/ToStringCast.h"

std::string ToStringCast::cast(double value) {
    return std::to_string(value);
}

std::string ToStringCast::get_description() const {
    return "Casting double to string using default 'to_string' function.";
}

std::string ToStringCast::get_name() const {
    return "ToStringCast";
}
