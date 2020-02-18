//
// Created by fenix on 2/18/20.
//

#include "../../include/cast_methods/QsNumberCast.h"
#include <qt/QtCore/QtCore>


std::string QsNumberCast::cast(double value) {
    return QString::number(value, 'F', 14).toStdString();
}

std::string QsNumberCast::get_description() const {
    return "Casting double to string using 'QString::number' function.";
}

std::string QsNumberCast::get_name() const {
    return "QsNumberCast";
}
