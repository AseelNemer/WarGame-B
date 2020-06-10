#ifndef UNTITLED_SNIPER_HPP
#define UNTITLED_SNIPER_HPP
#include "Soldier.hpp"


//namespace WarGame {



    class Sniper : public Soldier {
    public:

        explicit Sniper(int teamid): Soldier(100, 50, teamid) {}
        ~Sniper()
        {
            delete this;
        }

        int activate(std::vector<std::vector<Soldier*>> &board, int rows, int cols) override;
        int get_id() override;
        void return_to_max_health() override;
    }; 
    #endif