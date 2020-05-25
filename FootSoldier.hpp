#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>
#include "Soldier.hpp"

#define FS_HP 100
#define FS_DPA 10

class FootSoldier : public Soldier{
public:
    FootSoldier(int team):Soldier(FS_HP, FS_DPA, team, false){};
    ~FootSoldier(){};
    void attack(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> source) override{
        int enemyTeam = _team;
        if(enemyTeam == 1) enemyTeam = 2;
        else enemyTeam = 1;
        
    }
    void specialAttack(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> source) override{
        
    }
    void heal() override{
        
    }
    
    

};
