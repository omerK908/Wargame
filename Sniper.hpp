#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>
#include "FootSoldier.hpp"

#define S_HP 100
#define S_DPA 50

class Sniper : public FootSoldier
{
public:
    Sniper(int team) : FootSoldier(S_HP, S_DPA, team, false, Soldier::Sniper){};
    ~Sniper(){};

    // void specialAttack(std::vector<std::vector<Soldier *>> &board, std::pair<int, int> source) override
    // {

    //     std::cout << "--->Sniper Attack<--- " << std::endl;
    //     attack(board, source);
    // }
    void heal() override
    {
        _hp = S_HP;
    }
};
