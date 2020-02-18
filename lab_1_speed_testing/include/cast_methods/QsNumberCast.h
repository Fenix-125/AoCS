//
// Created by fenix on 2/18/20.
//

#ifndef LAB_1_SPEED_TESTING_QSNUMBERCAST_H
#define LAB_1_SPEED_TESTING_QSNUMBERCAST_H


#include "AbstractCastDoubleFunction.h"

class QsNumberCast : public AbstractCastDoubleFunction {

public:
    QsNumberCast() = default;

    std::string cast(double value) override;

    std::string get_description() const override;

    std::string get_name() const override;
};


#endif //LAB_1_SPEED_TESTING_QSNUMBERCAST_H
