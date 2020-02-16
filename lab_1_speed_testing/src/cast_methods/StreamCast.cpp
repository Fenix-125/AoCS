//
// Created by fenix on 2/13/20.
//

#include "../../include/cast_methods/StreamCast.h"


// Need to be cleared before use!!!
std::string StreamCast::cast(double value) {
    stream.str("");  // TODO: test if it clear the stream
    stream << value;
    return std::string();
}

std::string StreamCast::get_description() const {
    return "Use streams to cast double to string.";
}

std::string StreamCast::get_name() const {
    return "StreamCast";
}
