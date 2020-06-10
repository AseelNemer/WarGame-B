#ifndef UNTITLED_PARAMEDICCOMMANDER_PP
#define UNTITLED_PARAMEDICCOMMANDER_PP
#include "Soldier.hpp"
#include "Paramedic.hpp"


//#define MAX_HEALTH 200

//namespace WarGame{
    class ParamedicCommander : public Soldier{
       

        public:
        ParamedicCommander(int id): Soldier(200,0,id)  {}

         ~ParamedicCommander()
        {
            delete this;
        }
        
        
        int activate(std::vector<std::vector<Soldier*>> &board, int row, int col) override;
        int get_id()override;
        void return_to_max_health()override;

    };
#endif
//} 