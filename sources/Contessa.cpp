#include "Contessa.hpp"

using namespace coup;

Contessa::Contessa(Game &g, std::string name): Player(&g, std::move(name), "Contessa") {
    g.add_Player(*this);
}

void Contessa::block(Player &p){
    
    if(p.role() != "Assassin"){
        throw std::invalid_argument("Contessa can block assasins only");
    }
    if(p.action_object == nullptr ){
        throw std::invalid_argument("No action to block");
    }
    
    game->change_count(1);
    p.action_object->is_eliminated = false;
    p.action_object = nullptr;
}