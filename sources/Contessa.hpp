#include "Game.hpp"
namespace coup{
    
    class Contessa : public Player
    {
    public:
        Contessa(Game &g, std::string name);
    
        //unique traits
        void block(Player &p);
    };
    
}