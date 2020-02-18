//
// Created by fenix on 2/13/20.
//

#ifndef LAB_1_SPEED_TESTING_STREAMCAST_H
#define LAB_1_SPEED_TESTING_STREAMCAST_H


#include "AbstractCastDoubleFunction.h"
#include <sstream>

class StreamCast : public AbstractCastDoubleFunction {
public:
    StreamCast();

    std::string cast(double value) override;

    std::string get_description() const override;

    std::string get_name() const override;


private:
    std::stringstream stream;
};


#endif //LAB_1_SPEED_TESTING_STREAMCAST_H
