#pragma once
#include "Player.hpp"
#include <queue>

namespace coup{

    class Game{
        
        private:

        std::queue<Player *> players_q; 
        std::vector<std::string> plyrs;
        int players_count;
        bool game_started;
        public:
        Game();

        std::string turn();
        std::vector<std::string> players();
        std::string winner();
        void change_count(int n);
        
        void add_Player(Player &p);
        void remove_player(Player &p);
        void play(Player &p);
        int get_count(){return players_count;}

    };

}