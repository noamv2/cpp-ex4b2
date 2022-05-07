#include "Duke.hpp"
using namespace coup;

Duke::Duke(Game & g, std::string name):Player(&g,std::move(name), "Duke"){
    g.add_Player(*this);
}

void Duke::tax(){
    game->play(*this);
    change_balance(3);
    }

 void Duke::block(Player &p){
    if(!p.took_fa){
        throw std::invalid_argument("No foreign add taken");
    }
    p.change_balance(-2);
}