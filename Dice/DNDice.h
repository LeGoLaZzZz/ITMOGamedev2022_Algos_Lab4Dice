#ifndef LAB4DICE_DNDICE_H
#define LAB4DICE_DNDICE_H

#include <cstdlib>
#include "IDice.h"

class DNDice : public IDice {
    int sideN;
public:
    DNDice(int sideN) : sideN(sideN) {}

public:
    int GetRandomSide() const override {
        return 1 + rand() % sideN;
    }
};

#endif //LAB4DICE_DNDICE_H
