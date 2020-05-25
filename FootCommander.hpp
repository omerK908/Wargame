#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>
#include "Soldier.hpp"

#define FC_HP 150
#define FC_DPA 20

class FootCommander : public FootSoldier
{
public:
    FootCommander(int team) : FootSoldier(FC_HP, FC_DPA, team, true){};
    ~FootCommander(){};

    void specialAttack(std::vector<std::vector<Soldier *>> &board, std::pair<int, int> source) override
    {
        std::cout << "--->FootCommander Attack<--- " << std::endl;
        attack(board, source);
    }
    void heal() override
    {
        _hp = FC_HP;
    }
};
