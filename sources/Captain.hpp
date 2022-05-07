#pragma once

#include "Game.hpp"

namespace coup{
    class Captain: public Player
    {

    public:
        
        Captain(Game & g, std::string name);
        //unique traits
        void steal(Player &p); 
        void block(Player &p);
    };
}
