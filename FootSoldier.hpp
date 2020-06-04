#pragma once
#include <vector>
#include "Soldier.hpp"

#define MAX_HEALTH 100
#define HIT_DAMAGE 10

//namespace WarGame{
    class FootSoldier : public Soldier{
        private:
        int team_id;
        public:

        FootSoldier(int id): Soldier(MAX_HEALTH,HIT_DAMAGE,id){}
        
        ~FootSoldier()
        {
            delete this;
        }

        
        int activate(std::vector<std::vector<Soldier*>> &board, int row, int col) override;
        int get_id() override;
        void return_to_max_health() override;
        double dist(std::pair<int, int> from, std::pair<int, int> to);
    };

//}