#ifndef UNTITLED_PARAMEDIC_HPP
#define UNTITLED_PARAMEDIC_HPP
#include "Soldier.hpp"



//namespace WarGame{
    class Paramedic : public Soldier{
        
        

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
#endif
//} // namespace WarGame