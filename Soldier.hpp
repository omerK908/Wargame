#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>

class Soldier{
public:
    int _hp;
    int _dpa;
    int _team;
    bool _isCommander;

    Soldier(int hp, int dpa, int team, bool com):_hp(hp), _dpa(dpa), _team(team), _isCommander(com){}
    virtual ~Soldier(){};

    virtual void attack(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> source) = 0;
    virtual void specialAttack(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> source) = 0;
    virtual void heal() = 0;

};
