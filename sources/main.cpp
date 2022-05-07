#include <iostream>
#include "Player.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
#include "Game.hpp"

using namespace coup;

void printPLayers(Game g){
    for(std::string name : g.players()){
        std::cout<<name<<std::endl;
    }
}
int pmain(){

    Game g;
    Captain c {g, "noam"};
    Ambassador c2 {g, "noam2"};
    Assassin a {g, "tim"};
    printPLayers(g);
    c.income();
    c2.income();
    c.income();
    c2.foreign_aid();
    c.steal(c2);
    c2.block(c);
    a.foreign_aid();
    a.foreign_aid();
    a.coup(c);
    c2.foreign_aid();
    c2.foreign_aid();
    c2.foreign_aid();
    c2.coup(a);
    
    printPLayers(g);
    return 0;

}