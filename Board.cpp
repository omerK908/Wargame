#include <stdexcept>
#include "Board.hpp"
#include "Soldier.hpp"

using namespace std;

namespace WarGame {
    Soldier *& Board::operator[](std::pair<int, int> location) {
        return board[location.first][location.second];
    }
    Soldier* Board::operator[](std::pair<int,int> location) const{
        return board[location.first][location.second];
    }
    void Board::move(uint player_number, std::pair<int,int> source, MoveDIR direction){
        return;
    }
    bool Board::has_soldiers(uint player_number) const{
      
        for(int i = 0; i < board.size(); i++){
            vector<Soldier*> a = board[i];
            for(int j = 0; j < a.size(); j++){
                Soldier* s = a[j];
                if(s != NULL && s->_team == player_number) return true;
            }
        }
        return false;
    }
}