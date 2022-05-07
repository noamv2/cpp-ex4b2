#include "Game.hpp"
using namespace coup;

Player::Player(std::string name, std::string role):balance{0}, name{name}, role_name{role},took_fa{false}, is_eliminated{false}{

}

Player::Player(Game * g, std::string name, std::string role):game{g},balance{0}, name{name}, role_name{role},took_fa{false},is_eliminated{false}{
}

void Player::income(){
    if(coins() > 9){
        throw std::invalid_argument("Must coup with the current amount of coins");
    }
    game->play(*this);
    reset_actions();
    ++balance;
}

void Player::foreign_aid(){
    if(coins() > 9){
        throw std::invalid_argument("Must coup with the current amount of coins");
    }
    game->play(*this);
    reset_actions();
    took_fa = true;
    balance += 2;
}

 void Player::coup(Player & p){
    
    reset_actions();
    if(balance < 7){
        throw std::invalid_argument("Insufficient funds to coup");
    }
    
    game->remove_player(p);
    game->play(*this);
    change_balance(-7);
}

std::string Player::role(){

    return role_name;
}
int Player::coins(){
    return balance; 
}


int Player::change_balance(int sum){
    int old_bal = balance;
    balance += sum;
    if(balance < 0){
        balance = 0;
    }
    //returns the change in the balance
    return balance - old_bal;
}
void Player::reset_actions(){
    action_object = nullptr;
    took_fa = false;
}

