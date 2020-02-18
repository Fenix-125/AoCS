//
// Created by fenix on 2/13/20.
//

#include <iomanip>
#include "../../include/cast_methods/StreamCast.h"


StreamCast::StreamCast() {
    stream << std::fixed << std::setprecision(14);
}

std::string StreamCast::cast(double value) {
    stream.str("");
    stream << value;
    return stream.str();
}

std::string StreamCast::get_description() const {
    return "Use streams to cast double to string.";
}

std::string StreamCast::get_name() const {
    return "StreamCast";
}
