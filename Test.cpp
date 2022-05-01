#include "Player.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
#include "Game.hpp"
#include "doctest.h"

using namespace coup;

#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

TEST_CASE("Test"){
    Game game_1{};

    Duke duke{game_1, "Moshe"};
    Assassin assassin{game_1, "Yossi"};
    Ambassador ambassador{game_1, "Meirav"};
    Captain captain{game_1, "Reut"};
    Contessa contessa{game_1, "Gilad"};

    vector<string> players = game_1.players();
    CHECK_EQ(players.size(),5);
    CHECK_EQ(game_1.turn(),"Moshe");

    // throws no exceptions
    CHECK_NOTHROW(duke.income());
    CHECK_NOTHROW(assassin.income());
    CHECK_NOTHROW(ambassador.income());
    CHECK_NOTHROW(captain.income());
    CHECK_NOTHROW(contessa.income());

    // throws exception, it is duke's turn now
    CHECK_THROWS(assassin.income());

    duke.income();
    assassin.foreign_aid();

    // throws exception, the last operation duke performed
    // is income, which cannot be blocked by any role
    CHECK_THROWS(captain.block(duke));

    CHECK_EQ(duke.coins(),"2");
    CHECK_EQ(assassin.coins(),"3");

    // throws exception, the last operation duke performed
    // is foreign aid, which cannot be blocked by contessa
    CHECK_THROWS(contessa.block(assassin));

    CHECK_NOTHROW(duke.block(assassin));
    CHECK_EQ(assassin.coins(),"1");

    ambassador.transfer(duke, assassin); //transfers 1 coin from duke to assassin
    CHECK_EQ(assassin.coins(),"2");
    CHECK_EQ(duke.coins(),"1");

    captain.foreign_aid();
    contessa.foreign_aid();
    CHECK_EQ(captain.coins(),"3");
    CHECK_EQ(contessa.coins(),"3");

    duke.tax();
    CHECK_EQ(duke.coins(),"5");
    assassin.income();
    ambassador.foreign_aid();
    captain.steal(contessa);
    CHECK_EQ(captain.coins(),"5");
    CHECK_EQ(contessa.coins(),"1");
    contessa.foreign_aid();

    duke.tax();
    // no exception, assassin can coup with only 3 coins
    CHECK_NOTHROW(assassin.coup(duke));
    players = game_1.players();
    CHECK_EQ(players.size(),4);

    contessa.block(assassin);

    players = game_1.players();
    CHECK_EQ(players.size(),5);
    CHECK_THROWS(game_1.winner()); // nobody won yet
    CHECK_EQ(assassin.coins(),"0");
    duke.income();
    CHECK_THROWS(assassin.coup(duke));


}