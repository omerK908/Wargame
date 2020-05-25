#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>
#include "Soldier.hpp"

#define FC_HP 150
#define FC_DPA 20

class FootCommander : public Soldier
{
public:
    FootCommander(int team) : Soldier(FC_HP, FC_DPA, team, true){};
    ~FootCommander(){};
    void attack(std::vector<std::vector<Soldier *>> &board, std::pair<int, int> source) override
    {
    }
    void specialAttack(std::vector<std::vector<Soldier *>> &board, std::pair<int, int> source) override
    {
        std::cout << "FootCommander att" << std::endl;
    }
    void heal() override
    {
    }
};
