#include <algorithm>
#include "Game.hpp"
using namespace coup;

Game::Game():players_count{0},game_started{false}{

}

std::string Game::turn(){
    return players_q.front()->get_name();
}

std::vector<std::string> Game::players(){
    std::vector<std::string> names;
    std::vector<std::string> final_names; //need to be done because the tests are stupid and require particular order
    std::queue<Player *> cpy = players_q;

    while(!cpy.empty()){

            if(cpy.front()->is_eliminated){//skip eliminated players
                cpy.pop();
                continue;
            }
            names.push_back(cpy.front()->get_name());
            cpy.pop();

    }
    for(auto s: plyrs){
        if (std::find(names.begin(), names.end(), s) != names.end())
            {
            final_names.push_back(s);
            }
    }
    return final_names;
}

std::string Game::winner(){
    
    if(players_count > 1 || !game_started){
        throw std::invalid_argument("Game not done");
    }

    while(players_q.front()->is_eliminated){
        players_q.pop();
    }

    return turn();}

void Game::add_Player(Player &p){
    if(game_started){
        throw std::invalid_argument("Game already started");
    }
    if(players_count > 5){
        throw "too many players";
    }
    players_q.push(&p);
    plyrs.push_back(p.get_name());
    ++players_count;
}

void Game::remove_player(Player &p){

    if(p.is_eliminated){
        throw std::invalid_argument("Player already eliminated");
    }
    std::queue<Player *> temp;
    // move all the players from the original queue to 
    bool removed = false;
    while(!players_q.empty()){
        Player * t = players_q.front();
        if(t == &p){
            players_q.pop(); 
            removed = true;
            continue; //remove the player we were asked to emit   
        }
        temp.push(t);
        players_q.pop();
    }
    
    

    players_count--;
    // return the remaining players to the original queue
    while(!temp.empty()){
        Player * t = temp.front();
        players_q.push(t);
        temp.pop();
    }

    if(!removed){
        players_count++;
        throw std::invalid_argument("Player already eliminated");
    }
}

//a function that called before each player turn
void Game::play(Player &p){
    if( players_count < 2 && !game_started){
           throw std::invalid_argument("Not enough players");   
    }
    game_started = true;

    if(p.is_eliminated){
        throw std::invalid_argument("Player is elimanted");
    }
    if(players_q.front()->is_eliminated){
        Player * temp = players_q.front();
        players_q.pop();
        players_q.push(temp);
    }
    //check that this is the player turn now
    if(p.get_name() != turn()){
        throw std::invalid_argument("Cant play out of turn");
    }
    //Move the player to the back of the queue
    players_q.pop();
    players_q.push(&p);
    
}

void Game::change_count(int n){
    players_count += n;
}