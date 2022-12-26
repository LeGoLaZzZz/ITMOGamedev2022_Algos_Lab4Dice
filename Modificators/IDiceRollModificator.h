#ifndef LAB4DICE_IDICEROLLMODIFICATOR_H
#define LAB4DICE_IDICEROLLMODIFICATOR_H
class IDiceRollModificator {
public:
    virtual int Modifiy(int rollResult) const = 0;
};

#endif //LAB4DICE_IDICEROLLMODIFICATOR_H
