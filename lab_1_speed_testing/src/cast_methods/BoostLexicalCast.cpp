//
// Created by fenix on 2/16/20.
//

#include "../../include/cast_methods/BoostLexicalCast.h"
#include <boost/lexical_cast.hpp>


std::string BoostLexicalCast::cast(double value) {
    return boost::lexical_cast<std::string>(value);
}

std::string BoostLexicalCast::get_description() const {
    return "Casting double to string using 'boost::lexical_cast' function.";
}

std::string BoostLexicalCast::get_name() const {
    return "BoostLexicalCast";
}
