#include <vector>
#include <iostream>
#include <stdio.h>
#include <limits>
#include <cfloat>
#include <math.h>      
#include "FootCommander.hpp"
#include "Board.hpp"
using namespace std;

#define MAX_HEALTH 150
#define HIT_DAMAGE 20

//namespace WarGame
//{
    int FootCommander::activate(std::vector<std::vector<Soldier*>> &board, int row, int col) 
    {

        //to get the location of the closer solider to this solider
        std::pair<int,int > loc;
        double min_dist=DBL_MAX;
        double distance;
        for(int i=0 ;i<board.size();i++)
        {
            for(int j=0;j<board.at(i).size();j++)
            {
                 if (board[i][j] != nullptr && this->team_id!=board[i][j]->get_id()&& board[i][j]->get_id() != 0) 
                 {
                    std::pair<int,int> from;
                   from.first=row;
                   from.second=col;
                   std::pair<int,int> to;
                   to.first=i;
                   to.second=j;
                    distance= FootCommander::dist(from, to );
                    
                    if(distance <min_dist)
                      { 
                        min_dist=distance;
                        loc.first=i;
                        loc.second=j;
                      }
                }
                //check if there is another footsolider and send it to the activate function
                if(board[i][j]!=nullptr && (typeid(board[i][j])==typeid(FootSoldier)))
                    board[i][j]->activate(board,i,j);

            }
        
        }
        // loc is the locatcion of closer player to this player
        if(min_dist<DBL_MAX)
        {
            board[loc.first][loc.second]->health-=HIT_DAMAGE;
            if(board[loc.first][loc.second]->health<=0)
             {  
                delete board[loc.first][loc.second];
                board[loc.first][loc.second]=nullptr;

                return 1;
             }
        //did not remove a solider!
         return 0; 
        }      
    }

   

    int FootCommander::get_id()
    {
        return this->team_id;
    }

    void FootCommander::return_to_max_health()
    {
        this->health= MAX_HEALTH;
    }
    
    double FootCommander::dist(std::pair<int, int> from, std::pair<int, int> to)
    {
        return sqrt(pow(from.first-to.first,2) + pow(from.second - to.second,2));
    }
//}    