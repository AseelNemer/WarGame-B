#pragma once
#include <string>
#include <stdexcept>
#include "Soldier.hpp"

#define MAX_HEALTH 100

//namespace WarGame{
    class Paramedic : public Soldier{
        protected:
        int team_id;
        

        public:
        Paramedic(int id): Soldier(100,0,id){}

         ~Paramedic()
        {
            delete this;
        }
        
        int activate(std::vector<std::vector<Soldier*>> &board, int row, int col) override;
        int get_id()override;
        void return_to_max_health()override;
    };

//} // namespace WarGame