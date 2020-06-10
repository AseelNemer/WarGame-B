#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>
#include "SniperCommander.hpp"
#include "Board.hpp"
using namespace std;
//#define MAX_HEALTH 120
//#define HIT_DAMAGE 100


//namespace WarGame{
    int SniperCommander::activate(std::vector<std::vector<Soldier*>> &board, int row, int col) 
    {
        //to find the player in another team who has the most health 
       int strong=0;
       std::pair<int,int> loc;
       for(int i=0;i<board.size();i++)
       {
           for(int j=0;j<board.at(i).size();j++)
           {
               if(board[i][j]!=nullptr&& board[i][j]->team_id!=this->team_id)
               {
                   if(board[i][j]->health > strong)
                   {
                       strong=board[i][j]->health;
                       loc.first=i;
                       loc.second=j;
                   }
               }
               if(board[i][j]!=nullptr && board[i][j]->team_id== this->team_id)
                   if(dynamic_cast<Sniper*>(board[i][j])) 
                   board[i][j]->activate(board,i,j);
           }
       }
       //if there is a solider with a most health
       if(board[loc.first][loc.second]!=nullptr )
       {
           board[loc.first][loc.second]->health-=100;
            if(board[loc.first][loc.second]->health<=0)
             {  
                delete board[loc.first][loc.second];
                board[loc.first][loc.second]=nullptr;
                return 1;
             }
       }
       return 0;
    }

    int SniperCommander::get_id()
    {
        return this->team_id;

    }

    void SniperCommander::return_to_max_health()
    {   
        this->health=120;
    }
//}