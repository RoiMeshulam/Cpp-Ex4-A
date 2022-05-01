#ifndef EX4_PARTA_GAME_H
#define EX4_PARTA_GAME_H

#endif //EX4_PARTA_GAME_H

#pragma once
#include <string>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <vector>
//#include "Player.hpp"

using namespace std;

namespace coup{
    class Game {
    public:
        vector<string> _players; // all players active in game
        int _turn;
        Game();
        ~Game();
        string turn();
        vector<string> players();
        string winner();


    };
}