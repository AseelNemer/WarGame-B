#pragma once
#include <string>
#include <vector>
#include <stdexcept>
#include "Sniper.hpp"
#include "Soldier.hpp"

#define MAX_HEALTH 120
#define HIT_DAMAGE 100

//namespace WarGame{
    class SniperCommander : public Soldier{
        protected: 
        int team_id;

        public:
        SniperCommander(int id): Soldier(MAX_HEALTH,HIT_DAMAGE,id){}

         ~SniperCommander()
        {
            delete this;
        }

        int activate(std::vector<std::vector<Soldier*>> &board, int row, int col) override;
        int get_id() override;
        void return_to_max_health() override;

    };

//} 