#include <iostream>
#include <stdexcept>
#include "Board.hpp"


using namespace std;
namespace WarGame{
Soldier* &Board::operator[](std::pair<int, int> location)
    {
        return board[location.first][location.second];
    }

    Soldier* Board::operator[](std::pair<int, int> location) const
    {
        return board[location.first][location.second];

    }

    
void Board::move(uint teamID, std::pair<int,int> source, WarGame::Board::MoveDIR direction)
{
        
        int x=source.first;
        int y=source.second;
        
        if( x < 0 ||  x >=board.size()   ||  y<0 ||  y>=board[0].size())
                throw std::invalid_argument("You are off the board");
        if(board[x][y]==nullptr || board[x][y]->team_id !=teamID)
                throw std::invalid_argument("you do not have a solider in this place");
        
        if(direction== WarGame::Board::MoveDIR::Up)
        {
                if((x+1)>=board.size() || board[x+1][y]!=nullptr){
                        throw std::invalid_argument("You cannot go up you will be out of the board or there is another solider there!");
               } else {
                        board[x+1][y]=board[x][y];
                        //delete board[x][y];
                        board[x][y]=nullptr;
                        if(board[x][y]==nullptr)
                        board[x+1][y]->activate(board,x+1,y);

                }


        }
        if(direction== WarGame::Board::MoveDIR::Down)
        {
                if(x-1<0 || board[x-1][y]!=nullptr){
                        throw std::invalid_argument("You cannot go down you will be out of the board or there is another solider there!");
                }else {
                        board[x-1][y]=board[x][y];
                        board[x][y]=nullptr;
                        board[x-1][y]->activate(board,x-1,y);
                }
        }
        if(direction== WarGame::Board::MoveDIR::Right)
        {
                if(y+1>=board[0].size() || board[x][y+1]!=nullptr){
                        throw std::invalid_argument("You cannot right up you will be out of the board or there is another solider there!");
        }else
                { 
                        board[x][y+1]=board[x][y];
                        //delete board[x][y];
                        board[x][y]=nullptr;
                        board[x][y+1]->activate(board,x,y+1);
                }
        }
        if(direction== WarGame::Board::MoveDIR::Left)
        {
                if(y-1>=board[0].size() || board[x][y-1]!=nullptr){
                        throw std::invalid_argument("You cannot go left you will be out of the board or there is another solider there!");
                 } else
        { 
                        board[x][y-1]=board[x][y];
                        //delete board[x][y];
                        board[x][y]=nullptr;
                        board[x][y-1]->activate(board,x,y-1);
        }
        }

}


bool Board ::has_soldiers(uint teamID) const
{
        for(int i=0;i<board.size();i++)
        {
                for(int j=0;j<board[i].size();j++)
                {
                        //find solider with same team id and return true
                        if(board[i][j] != nullptr && board[i][j]->team_id==teamID)
                            {   
                                return true;
                            }
                }
        }
        // did not find solider with same team id  return false
        return false;
}

void Board ::print()
{

}

};