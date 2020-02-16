//
// Created by fenix on 2/16/20.
//

#ifndef LAB_1_SPEED_TESTING_BOOSTLEXICALCAST_H
#define LAB_1_SPEED_TESTING_BOOSTLEXICALCAST_H


#include "AbstractCastDoubleFunction.h"

class BoostLexicalCast : public AbstractCastDoubleFunction {
public:
    BoostLexicalCast() = default;

    std::string cast(double value) override;

    std::string get_description() const override;

    std::string get_name() const override;
};


#endif //LAB_1_SPEED_TESTING_BOOSTLEXICALCAST_H
