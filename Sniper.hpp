#pragma once
#include <string>
#include <vector>
#include <stdexcept>
#include "Soldier.hpp"

#define MAX_HEALTH 100
#define HIT_DAMAGE 50

//namespace WarGame
//{
    class Sniper : public Soldier{
        protected:
        int team_id;

        public:
        Sniper(int id) :Soldier(MAX_HEALTH,HIT_DAMAGE,id) {}

        ~Sniper()
        {
            delete this;
        }

        
        int activate(std::vector<std::vector<Soldier*>> &board, int row, int col) override;
        int get_id()override;
        void return_to_max_health()override;
        
    };

//} 