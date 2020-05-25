#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>
#include "Soldier.hpp"

#define PC_HP 200
#define PC_DPA 200

class ParamedicCommander : public Soldier{
public:
    ParamedicCommander(int team):Soldier(PC_HP, PC_DPA, team, true){};
    ~ParamedicCommander(){};
    void attack(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> source) override{
        
    }
    void specialAttack(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> source)override{
        
    }
    void heal() override{
        
    }

};
