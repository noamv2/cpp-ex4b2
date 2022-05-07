#include "Assassin.hpp"

using namespace coup;

Assassin::Assassin(Game &g, std::string name):Player(&g, std::move(name), "Assassin"){
    g.add_Player(*this);
}

void Assassin::assisnate(){
    //check if the assassin killed someone on the previous round, if so
    //we eliminate him from the game 
    if(action_object != nullptr){
        game->remove_player(*action_object);
        game->change_count(1); // add one to count due to double elimination
        action_object->is_eliminated = false;
    }
}
void Assassin::income(){
    
    game->play(*this);
    reset_actions();
    change_balance(1);
}

void Assassin::foreign_aid(){
    
    game->play(*this);
    reset_actions();
    took_fa = true;
    change_balance(2);
}

void Assassin::coup(Player &p){
    
    if(coins() >= COUP_COST){
        game->play(*this);
        game->remove_player(p);
        change_balance(-COUP_COST);
        return;
    }
    
    if(coins() < 3){
        throw std::invalid_argument("Insufficient funds");
    }

    if(game->get_count() == 2){ //in case this is the last player remaining
        game->remove_player(p);
        change_balance(-3);
        return;
    }
    change_balance(-3);
    game->play(*this);
    action_object = &p;
    p.is_eliminated = true;
    game->change_count(-1);
}

