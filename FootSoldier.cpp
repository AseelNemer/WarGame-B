#include <vector>
#include <iostream>
#include <stdio.h>
#include <limits>
#include <cfloat>
#include <math.h>       
#include "FootSoldier.hpp"
#include "Board.hpp"

using namespace std;
#define MAX_HEALTH 100
#define HIT_DAMAGE 10

//namespace WarGame{        
    
   int FootSoldier::activate(std::vector<std::vector<Soldier*>> &board, int row, int col) 
    {
        //to get the location of the closer solider to this solider
        std::pair<int,int > loc;
        double min_dist=DBL_MAX;
        double distance;
        for(int i=0 ;i<board.size();i++)
        {
            for(int j=0;j<board.at(i).size();j++)
            {
                 if (board[i][j] != nullptr && this->team_id!=board[i][j]->get_id()&& board[i][j]->get_id() != 0) {
                   std::pair<int,int> from;
                   from.first=row;
                   from.second=col;
                   std::pair<int,int> to;
                   to.first=i;
                   to.second=j;
                    distance= FootSoldier::dist(from, to );
                    
                    if(distance <min_dist)
                      { 
                        min_dist=distance;
                        loc.first=i;
                        loc.second=j;
                      }
                }

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
                
        }
        //return  0 if there is no players to kill
        return 0;

    }

    int FootSoldier::get_id()
    {
        return this->team_id;
    }

    void FootSoldier::return_to_max_health()
    {
        this->health=MAX_HEALTH;
    }
    double FootSoldier::dist(std::pair<int, int> from, std::pair<int, int> to)
    {
        return sqrt(pow(from.first-to.first,2) + pow(from.second - to.second,2));
    }


//}