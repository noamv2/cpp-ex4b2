#include "Game.hpp"

using namespace coup;

Player::Player(std::string name, std::string role):game{nullptr}, action_object{nullptr},balance{0}, name{std::move(name)}, role_name{std::move(role)},took_fa{false}, is_eliminated{false}{

}

Player::Player(Game * g, std::string name, std::string role):action_object{nullptr}, game{g},balance{0}, name{std::move(name)}, role_name{std::move(role)},took_fa{false},is_eliminated{false}{
}

void Player::income(){
    if(coins() > COUP_COST + 2){
        throw std::invalid_argument("Must coup with the current amount of coins");
    }
    game->play(*this);
    reset_actions();
    ++balance;
}

void Player::foreign_aid(){
    if(coins() > COUP_COST + 2){
        throw std::invalid_argument("Must coup with the current amount of coins");
    }
    game->play(*this);
    reset_actions();
    took_fa = true;
    balance += 2;
}

 void Player::coup(Player & p){
    
    reset_actions();
    if(balance < COUP_COST){
        throw std::invalid_argument("Insufficient funds to coup");
    }
    
    game->remove_player(p);
    game->play(*this);
    change_balance(-COUP_COST);
}

std::string Player::role(){

    return role_name;
}
int Player::coins() const{
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

