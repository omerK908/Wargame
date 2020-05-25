#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>
#include "Soldier.hpp"

#define S_HP 100
#define S_DPA 50

class Sniper : public Soldier{
public:
    Sniper(int team):Soldier(S_HP, S_DPA, team, false){};
    ~Sniper(){};
    void attack(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> source) override{
        
    }
    void specialAttack(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> source) override{
        
    }
    void heal() override{
        
    }

};
