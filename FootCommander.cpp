#include <vector>
#include <iostream>
#include <stdio.h>
#include <limits>
#include <cfloat>
#include <math.h>      
#include "FootCommander.hpp"
#include "Board.hpp"
using namespace std;

//#define MAX_HEALTH 150
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
                 if (board[i][j] != nullptr && this->team_id!=board[i][j]->team_id) 
                 {
                   distance= pow(row-i,2)+pow(col-j,2);
                   cout<< "r== "<<row<<endl;
                        cout << "c== "<< col<<endl;
                    
                    if(distance < min_dist)
                      { 
                        min_dist=distance;
                        loc.first=i;
                        loc.second=j;
                        cout<< "i== "<<i<<endl;
                        cout << "j== "<< j<<endl;
                      }
                }
                //check if there is another footsolider and send it to the activate function
                if(board[i][j]!=nullptr && (typeid(board[i][j])==typeid(FootSoldier))&&board[i][j]->team_id== this->team_id)
                    board[i][j]->activate(board,i,j);

            }
        
        }
        // loc is the locatcion of closer player to this player
        if(board[loc.first][loc.second]!=nullptr)
        {
            cout <<board[loc.first][loc.second]->health<<endl;
            board[loc.first][loc.second]->health-=HIT_DAMAGE;
            if(board[loc.first][loc.second]->health <= 0)
             {  
                 cout<< "yesss"<<endl;
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
        this->health= MAX_HEALTH;
    }
    
//}    