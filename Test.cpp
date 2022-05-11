#include <exception>
#include "doctest.h"
#include "Game.hpp"
#include "Player.hpp"
#include "Contessa.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"

using namespace coup;
TEST_CASE("legal moves"){

    Game game;
    Duke duke {game,"duke1"};
    Duke duke2 {game,"duke2"};
    Assassin assassin {game, "assassin"};
    Captain cap {game, "captain"};

    //check income
    CHECK_NOTHROW(duke.income());
    CHECK_NOTHROW(duke2.income());
    CHECK_NOTHROW(assassin.income());
    CHECK_NOTHROW(cap.income());
    
    CHECK(duke.coins() == 1);
    CHECK(duke2.coins() == 1);
    CHECK(assassin.coins() == 1);
    CHECK(cap.coins() == 1);

    //check foreign_aid
    CHECK_NOTHROW(duke.foreign_aid());
    CHECK_NOTHROW(duke2.foreign_aid());
    CHECK_NOTHROW(assassin.foreign_aid());
    CHECK_NOTHROW(cap.foreign_aid());
    
    CHECK(duke.coins() == 3);
    CHECK(duke2.coins() == 3);
    CHECK(assassin.coins() == 3);
    CHECK(cap.coins() == 3);

    //check duke's blocking function
    CHECK_NOTHROW(duke.block(duke2));
    CHECK_NOTHROW(duke.block(assassin));
    CHECK_NOTHROW(duke.block(cap));

    CHECK(duke.coins() == 3);
    CHECK(duke2.coins() == 1);
    CHECK(assassin.coins() == 1);
    CHECK(cap.coins() == 1);



}

TEST_CASE("Bad scenarios")
    {
        Game g {};
        Duke duke(g, "Moshe");
	    Assassin assassin{g, "Yossi"};
	    Ambassador ambassador{g, "Meirav"};
	    Captain captain{g, "Reut"};
	    Contessa contessa{g, "Gilad"};
	    Contessa contessa2{g, "asdfad"};
	    try{
            Contessa contessa3{g, "asdfad"};
            CHECK_EQ(1, 0);
        }
        catch(std::exception &e){}

        Game g1 {};
        Duke duke(g1, "Moshe");

        //Not enought players
        CHECK_THROWS(duke.income());
        Duke duke2(g1, "Eli");
        Duke duke3(g1, "ben");
        Duke duke4(g1, "dan");

        //check turn system

        //Correct turn order
        CHECK_NOTHROW(duke.income());
        CHECK_NOTHROW(duke2.income());
        CHECK_NOTHROW(duke3.income());
        CHECK_NOTHROW(duke4.income());

        //Wrong turn order
        CHECK_THROWS(duke2.income());
        CHECK_THROWS(duke3.income());
        CHECK_THROWS(duke4.income());
        duke.income();
        CHECK_THROWS(duke.foreign_aid());
        
    }

    TEST_CASE("Block functions"){

        Game g {};
        Duke d(g, "Moshe");
	    Assassin as{g, "Yossi"};
	    Ambassador am{g, "Meirav"};
	    Captain cap{g, "Reut"};
	    Contessa con{g, "Gilad"};

        CHECK_NOTHROW(d.foreign_aid());
        CHECK_NOTHROW(as.foreign_aid());
        d.block(as);
        // check Duke's foreign aid Block
        CHECK(as.coins() == 0);
        am.foreign_aid();

        //Check Captin steal Block
        cap.steal(am);
        am.block(cap);
        CHECK(am.coins() == 2);

        con.foreign_aid();
        d.income();
        as.income();
        am.income();
        cap.income();
        con.income();
        d.income();

        //check assasin coup and contessa block functions
        CHECK_NOTHROW(as.coup(am));
        con.block(as);
        CHECK(g.get_count() == 6);

    }