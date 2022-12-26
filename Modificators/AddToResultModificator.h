#ifndef LAB4DICE_ADDTORESULTMODIFICATOR_H
#define LAB4DICE_ADDTORESULTMODIFICATOR_H

#include "IDiceRollModificator.h"

class AddToResultModificator : public IDiceRollModificator {
    int addAmount;
public:
    AddToResultModificator(int addAmount) : addAmount(addAmount) {}

public:
    int Modifiy(int rollResult) const override {
        return rollResult + addAmount;
    }
};

#endif //LAB4DICE_ADDTORESULTMODIFICATOR_H
