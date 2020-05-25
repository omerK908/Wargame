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

        int row = source.first;
        int col = source.second;
        if (row >= board.size() || row < 0 || col >= board[row].size() || col < 0)
        {
            throw std::invalid_argument("out of bound");
        }
        
        Soldier* temp = this->board[row][col];

        if (temp == nullptr)
        {
            throw std::invalid_argument("place is empty");
        }
        
        std::cout <<"team: "<< temp->_team <<" commander: " << temp->_isCommander << std::endl;
        

        if(temp != nullptr && temp->_team == player_number){
            //std::cout << temp << std::endl;

            switch (direction)
            {
            case Up:
                if(isEmpty({row+1,col})){
                    board[row][col] = nullptr;
                    attack({row+1,col}, temp);
                    board[row+1][col] = temp;
                }
                
                break;
            case Down:
                if(isEmpty({row-1,col})){
                    board[row][col] = nullptr;
                    attack({row-1,col}, temp);
                    board[row-1][col] = temp;
                }
                
                break;
            case Right:
                if(isEmpty({row,col+1})){
                    board[row][col] = nullptr;
                    attack({row,col+1}, temp);
                    board[row][col+1] = temp;
                }
                
                break;
            case Left:
               if(isEmpty({row,col-1})){
                   board[row][col] = nullptr;
                    attack({row,col-1}, temp);
                    board[row][col-1] = temp;
               }
                
                break;
            
            default:
                break;
            }
        }
        else
        {
            throw std::invalid_argument("place is not belong to you");
        }
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
    void Board::attack(std::pair<int, int> loc, Soldier* soldier){
        soldier->specialAttack(this->board, loc);
    }
        
}