#pragma once

#include "Game.hpp"

namespace coup{


    class Ambassador:public Player
    {
    public:
        Ambassador(Game & g, std::string name);
        
        //unique traits

        void transfer(Player &from, Player & to);
        void block(Player &p);
     

    };
}