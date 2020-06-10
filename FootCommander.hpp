#ifndef UNTITLED_FOOTCOMMANDER_HPP
#define UNTITLED_FOOTCOMMANDER_HPP
#include "Soldier.hpp"
#include "FootSoldier.hpp"

//#define MAX_HEALTH 150
//#define HIT_DAMAGE 20

//namespace WarGame
//{
    class FootCommander : public Soldier{

       
        public:

        FootCommander(int id) : Soldier(150,20,id){}
         
         ~FootCommander()
        {
            delete this;
        }
        
        int activate(std::vector<std::vector<Soldier*>> &board, int row, int col) override;
        int get_id() override;
        void return_to_max_health() override;
        double dist(std::pair<int, int> from, std::pair<int, int> to);
        
    };
#endif
//} 