#pragma once
#include <string>
#include <vector>
#include <stdexcept>
#include "FootSoldier.hpp"
#include "Soldier.hpp"

#define MAX_HEALTH 150
#define HIT_DAMAGE 20

//namespace WarGame
//{
    class FootCommander : public Soldier{

        private:
        int team_id;
        public:

        FootCommander(int id) : Soldier(MAX_HEALTH,HIT_DAMAGE,id){}
         
         ~FootCommander()
        {
            delete this;
        }
        
        int activate(std::vector<std::vector<Soldier*>> &board, int row, int col) override;
        int get_id() override;
        void return_to_max_health() override;
        double dist(std::pair<int, int> from, std::pair<int, int> to);
        
    };

//} 