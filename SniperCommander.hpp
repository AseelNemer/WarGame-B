#ifndef UNTITLED_SNIPERCOMMANDER_HPP
#define UNTITLED_SNIPERCOMMANDER_HPP
#include "Sniper.hpp"
#include "Soldier.hpp"

//#define MAX_HEALTH 120
//#define HIT_DAMAGE 100

//namespace WarGame{
    class SniperCommander : public Soldier{
        

        public:
        SniperCommander(int id): Soldier(120,100,id){}

         ~SniperCommander()
        {
            delete this;
        }

        int activate(std::vector<std::vector<Soldier*>> &board, int row, int col) override;
        int get_id() override;
        void return_to_max_health() override;

    };
#endif
//} 