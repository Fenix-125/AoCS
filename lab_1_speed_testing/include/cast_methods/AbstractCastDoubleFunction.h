//
// Created by fenix on 2/12/20.
//

#ifndef LAB_1_SPEED_TESTING_ABSTRACTCASTDOUBLEFUNCTION_H
#define LAB_1_SPEED_TESTING_ABSTRACTCASTDOUBLEFUNCTION_H


#include <string>

class AbstractCastDoubleFunction {
public:
    virtual std::string cast(double value) = 0;

    virtual ~AbstractCastDoubleFunction() = default;

    virtual std::string get_description() const = 0;

    virtual std::string get_name() const = 0;
};


#endif //LAB_1_SPEED_TESTING_ABSTRACTCASTDOUBLEFUNCTION_H
