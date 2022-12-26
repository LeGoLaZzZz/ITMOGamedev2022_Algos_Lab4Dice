//
// Created by manat on 09.11.2022.
//

#ifndef LAB4DICE_D6DICE_H
#define LAB4DICE_D6DICE_H

#include <cstdlib>
#include "IDice.h"

class D6Dice : public IDice {
public:
    int GetRandomSide() const override {
        return 1 + rand() % 6;
    }
};
#endif //LAB4DICE_D6DICE_H
