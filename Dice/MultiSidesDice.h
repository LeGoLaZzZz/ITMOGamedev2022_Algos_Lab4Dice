//
// Created by manat on 09.11.2022.
//

#ifndef LAB4DICE_MULTISIDESDICE_H
#define LAB4DICE_MULTISIDESDICE_H

#include <cstdlib>
#include "IDice.h"

class MultiSidesDice : public IDice {

    int sideCount;
    int sides[];

public:
    int GetRandomSide() const override {
        return sides[rand() % sideCount];
    }
};

#endif //LAB4DICE_MULTISIDESDICE_H
