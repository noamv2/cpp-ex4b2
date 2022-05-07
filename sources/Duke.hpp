#pragma once

#include "Game.hpp"

namespace coup{
    class Duke : public Player
    {
    public:
        Duke(Game &g, std::string name);
        
        
        //unique traits
        void tax();
        void block(Player &p);

    };

}
