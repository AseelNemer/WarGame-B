#include <vector>
#include <iostream>
#include "Paramedic.hpp"
#include "Board.hpp"
using namespace std;

#define MAX_HEALTH 100


//namespace WarGame{
    int Paramedic::activate(std::vector<std::vector<Soldier*>> &board, int row, int col) 
    {
        int ans=0;
        if(board[row+1][col]!=nullptr && (board[row+1][col]->team_id==this->team_id))
        {
            board[row+1][col]->return_to_max_health();
            ans=1;
        }
         if(board[row-1][col]!=nullptr && (board[row-1][col]->team_id==this->team_id))
        {
             board[row-1][col]->return_to_max_health();
             ans=1;
        }
         if(board[row][col+1]!=nullptr && (board[row][col+1]->team_id==this->team_id))
        {
           board[row][col+1]->return_to_max_health();
           ans=1;
        }
         if(board[row][col-1]!=nullptr && (board[row][col-1]->team_id==this->team_id))
        {
           board[row][col-1]->return_to_max_health();
           ans=1;
        }
        return ans;
    }

    int Paramedic::get_id()
    {
        return team_id;
    }

    void Paramedic::return_to_max_health()
    {
        this->health=MAX_HEALTH;
    }
//}