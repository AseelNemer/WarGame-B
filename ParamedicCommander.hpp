#pragma once
#include <vector>
#include "Paramedic.hpp"
#include "Soldier.hpp"


#define MAX_HEALTH 200

//namespace WarGame{
    class ParamedicCommander : public Soldier{
        protected:
        int team_id;

        public:
        ParamedicCommander(int id): Soldier(MAX_HEALTH,0,id)  {}

         ~ParamedicCommander()
        {
            delete this;
        }
        
        
        int activate(std::vector<std::vector<Soldier*>> &board, int row, int col) override;
        int get_id()override;
        void return_to_max_health()override;

    };

//} 