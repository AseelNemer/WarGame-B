#include <vector>
#include <iostream>
#include "Paramedic.hpp"
#include "Board.hpp"
using namespace std;



//namespace WarGame{
    int Paramedic::activate(std::vector<std::vector<Soldier*>> &board, int row, int col) 
    {
        int ans=0;
        if(row < board.size()-2 && board[row+1][col] != nullptr && (board[row+1][col]->team_id == this->team_id))
        {
            board[row+1][col]->return_to_max_health();
        }
         if(row != 0 && board[row-1][col] != nullptr && (board[row-1][col]->team_id == this->team_id))
        {
             board[row-1][col]->return_to_max_health();
        }
         if(col <= board[0].size()-2 && board[row][col+1] != nullptr && (board[row][col+1]->team_id == this->team_id))
        {
           board[row][col+1]->return_to_max_health();
        }
         if(col!=0 && board[row][col-1] != nullptr && (board[row][col-1]->team_id == this->team_id))
        {
           board[row][col-1]->return_to_max_health();
        } 
        return ans;
    }

    int Paramedic::get_id()
    {
        return team_id;
    }

    void Paramedic::return_to_max_health()
    {
        this->health=100;
    }
//}