#pragma once

#include "Game.hpp"
namespace coup{
    class Assassin: public Player
    {
    public:
        Assassin(Game & g, std::string name);
        //unique traits
        void coup(Player &p);
        void income();
        void foreign_aid();
        void assisnate();
    };
}
