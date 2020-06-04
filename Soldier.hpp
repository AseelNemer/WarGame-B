#ifndef SOLDIER_HPP_
#define SOLDIER_HPP_
#include <string>
#include <vector>
#include <stdexcept>

//namespace WarGame{
  

  class Soldier
  {
    public:
      int health;
      int damage;
      int team_id;

  Soldier(int health, int damage,int team_id)
  {
    this->health=health;
    this->damage=damage;
    this->team_id=team_id;
    
  }
  

  
    virtual int activate(std::vector<std::vector<Soldier*>> &board, int rows, int cols) = 0;
    virtual int get_id() = 0;
    virtual void return_to_max_health()=0;

  };

//} 
#endif 