#include <iostream>
#include <vector>
#include "ParamedicCommander.hpp"
#include "Paramedic.hpp"
#include "Board.hpp"
using namespace std;

//#define MAX_HEALTH 200

//namespace WarGame{
    
    int ParamedicCommander::activate(std::vector<std::vector<Soldier*>> &board, int row, int col) 
    {
        if(row<board.size()-2 && board[row+1][col]!=nullptr && (board[row+1][col]->team_id==this->team_id))
        {
            board[row+1][col]->return_to_max_health();
        }
         if(row!=0 && board[row-1][col]!=nullptr && (board[row-1][col]->team_id==this->team_id))
        {
             board[row-1][col]->return_to_max_health();
        }
         if(col<=board[0].size()-2 && board[row][col+1]!=nullptr && (board[row][col+1]->team_id==this->team_id))
        {
           board[row][col+1]->return_to_max_health();
        }
         if(col!=0&&board[row][col-1]!=nullptr && (board[row][col-1]->team_id==this->team_id))
        {
           board[row][col-1]->return_to_max_health();
        } 

        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board.at(i).size();j++)
            {
                if(board[i][j]!=nullptr && (board[i][j]->team_id==this->team_id) )
                    {
                        if( dynamic_cast<Paramedic*>(board[i][j]))
                       
                     board[i][j]->activate(board,i,j);
                    }
            }
        }
        return 0;
    }

    int ParamedicCommander::get_id()
    {
        return this->team_id;
    }

    void ParamedicCommander::return_to_max_health()
    {
        this->health=200;
    }

//}