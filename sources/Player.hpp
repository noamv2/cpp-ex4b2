#pragma once
#include <string>
#include <vector>
#include <stdexcept>
const int COUP_COST = 7;
namespace coup{
    class Game;    //forward declraion of Game
    class Player
    {
    private:
        std::string role_name;
        std::string name;
        int balance;
        
    protected:
        Game *game;
    public:
        bool took_fa;
        bool is_eliminated;
        Player * action_object; // pointer to the player that was the object of the action, help revert it
        Player(std::string name, std::string role);
        Player(Game * g, std::string name, std::string role);
        Player(){}
        
        //common game actions
        void income();
        void foreign_aid();
        virtual void coup(Player &p) ;
        
        //getters
        std::string role();
        std::string get_name(){return name;}
        int coins() const;

        //methods
        int change_balance(int sum);
        void reset_actions();
    };
}