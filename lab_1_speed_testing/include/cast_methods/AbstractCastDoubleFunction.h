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
};


#endif //LAB_1_SPEED_TESTING_ABSTRACTCASTDOUBLEFUNCTION_H
