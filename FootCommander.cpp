
#pragma once
#include "FootSoldier.hpp"
#include <vector>
#include <iostream>
#include <stdio.h>
#include <limits>
#include <math.h>      
#include "FootCommander.hpp"
#include "Board.hpp"
using namespace std;

//#define MAX_HEALTH 150
//#define HIT_DAMAGE 20

//namespace WarGame
//{
    int FootCommander::activate(std::vector<std::vector<Soldier*>> &board, int row, int col) 
    {
        //to get the location of the closer solider to this solider
        std::pair<int,int > loc;
        double min_dist=board.size()*board[0].size();;
        double distance;
        for(int i=0 ;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                 if (board[i][j] != nullptr && this->team_id!=board[i][j]->team_id) 
                 {
                   distance= pow(row-i,2)+pow(col-j,2);
                    if(distance < min_dist)
                      { 
                        min_dist=distance;
                        loc.first=i;
                        loc.second=j;
                      }
                }
                
                
                //check if there is another footsolider and send it to the activate function
                if(board[i][j]!=nullptr  && board[i][j]->team_id== this->team_id)
                    {
                        if (dynamic_cast<FootSoldier*>(board[i][j]))
                            board[i][j]->activate(board,row,col);
                    }

            }
        
        }
        // loc is the locatcion of closer player to this player
        if(board[loc.first][loc.second]!=nullptr)
        {
            board[loc.first][loc.second]->health-=20;
            if(board[loc.first][loc.second]->health <= 0)
             {
                delete board[loc.first][loc.second];
                board[loc.first][loc.second]=nullptr;
                return 1;
             }
        
        } 
         //did not remove a solider!
         return 0;     
    }

   

    int FootCommander::get_id()
    {
        return this->team_id;
    }

    void FootCommander::return_to_max_health()
    {
        this->health= 150;
    }
    
//}    