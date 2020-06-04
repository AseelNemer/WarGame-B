#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
#include "Sniper.hpp"
#include "Board.hpp"
using namespace std;
//#define MAX_HEALTH 100
#define HIT_DAMAGE 50

//namespace WarGame
//{
   int Sniper::activate(std::vector<std::vector<Soldier*>> &board, int row, int col) 
   {
       //to find the player in another team who has the most points 
       int strong=0;
       std::pair<int,int> loc;
       for(int i=0;i<board.size();i++)
       {
           cout << "i= " << i<<endl;
           for(int j=0;j<board.at(i).size();j++)
           {
               if((board[i][j]!=nullptr) && (board[i][j]->team_id!=this->team_id))
               {
                   if(board[i][j]->health>strong)
                   {
                       strong=board[i][j]->health;
                       loc.first=i;
                       loc.second=j;
                   }
               }
           }
       }
       //if there is a solider with a most health
       if(strong>0 && board[loc.first][loc.second]!=nullptr )
       {
           board[loc.first][loc.second]->health-=HIT_DAMAGE;
            if(board[loc.first][loc.second]->health<=0)
             {  
                delete board[loc.first][loc.second];
                board[loc.first][loc.second]=nullptr;
                return 1;
             }
       }
       //there is no soliders with health
       return 0;
   }

    int Sniper::get_id()
    {
        return this->team_id;
    }

    void Sniper::return_to_max_health()
    {
        this->health=MAX_HEALTH;
    }
//}