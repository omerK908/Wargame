#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>
#include "Soldier.hpp"

#define P_HP 100
#define P_DPA 200

class Paramedic : public Soldier{
public:
    Paramedic(int team):Soldier(P_HP, P_DPA, team, false, Soldier::Paramedic){};
    ~Paramedic(){};
    void attack(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> source) override{
        
    }
    void specialAttack(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> source) override{
        
    }
    void heal() override{
        _hp = P_HP;
    }

};
