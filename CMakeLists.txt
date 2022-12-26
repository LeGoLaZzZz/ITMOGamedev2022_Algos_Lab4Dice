cmake_minimum_required(VERSION 3.22)
project(Lab4Dice)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab4Dice main.cpp Modificators/IDiceRollModificator.h Modificators/AddToResultModificator.h Dice/IDice.h Dice/D6Dice.h Dice/MultiSidesDice.h Dice/DNDice.h)
