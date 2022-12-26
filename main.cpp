#include <iostream>
#include "Dice/IDice.h"
#include "Modificators/IDiceRollModificator.h"
#include "Dice/D6Dice.h"
#include "Modificators/AddToResultModificator.h"
#include "Dice/DNDice.h"
#include <map>

struct DiceRollData {
    IDice *dice;
    int rollCount;
    IDiceRollModificator *modificators;
    int ModificatorsCount;
};

int RollDice(const IDice &dice, const int rollCount, const IDiceRollModificator *modificators,
             const int ModificatorsCount) {

    int resultSum = 0;
    for (int j = 0; j < rollCount; ++j) {
        int side = dice.GetRandomSide();
        resultSum += side;
    }

    for (int i = 0; i < ModificatorsCount; ++i) {
        resultSum = modificators[i].Modifiy(resultSum);
    }

    return resultSum;
}

int RollDice(const DiceRollData &diceData) {
    return RollDice(*(diceData.dice), diceData.rollCount, diceData.modificators, diceData.ModificatorsCount);
}

int RollDice(const DiceRollData *dices, const int dicesCount) {
    int resultSum = 0;
    for (int i = 0; i < dicesCount; ++i) resultSum += RollDice(dices[i]);
    return resultSum;
}

int RollDice(const std::initializer_list<DiceRollData> args) {
    int resultSum = 0;
    for (const auto &item: args) resultSum += RollDice(item);
    return resultSum;
}

void UsageRollDiceExamples() {
    auto d6 = D6Dice();
    auto d10 = DNDice(10);
    auto addMod = AddToResultModificator(10);

    for (int i = 0; i < 100; ++i) {
        std::cout << RollDice(d10, 3, &addMod, 1) << std::endl;
    }

    DiceRollData data3d6plus2 = {&d6, 3, &addMod, 1};
    DiceRollData data10d10 = {&d10, 10, &addMod, 1};
    DiceRollData datas[2];
    datas[0] = data3d6plus2;
    datas[1] = data10d10;

    RollDice(datas, 2);
    RollDice({data3d6plus2, data10d10});
}


std::map<int, int> TestDice(int diceN, int diceCount, int rollCount) {
    std::map<int, int> resultCounts;
    auto dice = DNDice(diceN);

    for (int i = 0; i < rollCount; ++i) {
        auto result = RollDice(dice, diceCount, nullptr, 0);
        resultCounts[result] += 1;
    }

    return resultCounts;
}


int main123() {
    srand(time(nullptr));

    auto d6 = DNDice(6);
    auto d10 = DNDice(10);

    auto rollCount = 100000;
    int diceN = 6;
    int diceCount = 2;

    std::map<int, int> resultCounts = TestDice(diceN, diceCount, rollCount);

    for (int i = 0; i < diceN * diceCount + 1; ++i) {
        std::cout << i << " " << resultCounts[i] << std::endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {

    int diceN = std::atoi(argv[1]);
    int diceCount = std::atoi(argv[2]);
    int rollCount = std::atoi(argv[3]);
//
//    std::cout << diceN << " " << diceCount << " " << rollCount << " " ;
    std::map<int, int> resultCounts = TestDice(diceN, diceCount, rollCount);

    for (int i = 0; i < diceN * diceCount + 1; ++i) {
        std::cout << i << " " << resultCounts[i] << std::endl;
    }
    return 0;
}

