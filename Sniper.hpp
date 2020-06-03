#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>
#include "FootSoldier.hpp"

#define S_HP 100
#define S_DPA 50
//#define HUGE_NUMBER 1000

class Sniper : public FootSoldier
{
public:
    Sniper(int team) : FootSoldier(S_HP, S_DPA, team, false, Soldier::Sniper){};
    Sniper(int hp, int dpa, int team, bool isCommander, Type type) : FootSoldier(hp, dpa, team, isCommander, type) {}
    ~Sniper(){};
    void attack(std::vector<std::vector<Soldier *>> &board, std::pair<int, int> source) override
    {
        //std::cout << "--->Sniper Attack<--- " << std::endl;
        std::pair<int, int> enemyPos = strongestEnemyPos(board);
        //std::cout << "enemyPos " << enemyPos.first << " " << enemyPos.second << std::endl;
        if(enemyPos.first < 0 || enemyPos.second < 0){
            //std::cout << "Didnt find strongest enemy, Sniper::attack\n";
            return;
        }
        Soldier* enemy = board[enemyPos.first][enemyPos.second];
        if (enemy != nullptr)
        {
            enemy->_hp -= this->_dpa;
            if(enemy->_hp <=0){
                delete enemy;
                board[enemyPos.first][enemyPos.second] = nullptr;
                //std::cout << " ---RIP---" << std::endl;
            }
        }
    }

    void specialAttack(std::vector<std::vector<Soldier *>> &board, std::pair<int, int> source) override
    {
        attack(board, source);
        if(_isCommander){
            //std::cout << "--->SniperCommander Attack<---______ " << std::endl;
            for (int i = 0; i < board.size(); i++)
            {
                std::vector<Soldier *> a = board[i];
                for (int j = 0; j < a.size(); j++)
                {
                    Soldier *s = a[j];
                    if (s != NULL && s->_team == _team && !s->_isCommander && s->_type == _type)
                        s->specialAttack(board, {i, j});
                }
            }
        }
    }
    void heal() override
    {
        _hp = S_HP;
    }

    std::pair<int, int> strongestEnemyPos(std::vector<std::vector<Soldier *>> &board)
    {
        //std::cout << "___________Find strongest enemy func__________\n";
        Soldier *tmp = nullptr;
        int enemyHp = 0;
        std::pair<int, int> ans = {-1, -1};
        
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                Soldier *s = board[i][j];
                if (s != nullptr && s->_team != _team && s->_hp > enemyHp){
                    enemyHp = s->_hp;
                    ans.first = i; ans.second = j;
                }

            }
        }
        return ans;
    }
};
