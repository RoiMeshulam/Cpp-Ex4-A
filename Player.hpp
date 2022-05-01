#ifndef EX4_PARTA_PLAYER_H
#define EX4_PARTA_PLAYER_H

#endif //EX4_PARTA_PLAYER_H

#pragma once
#include <string>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <vector>
#include "Game.hpp"

using namespace std;

namespace coup{
    class Player {
    public:
        int _numOfCoins;
        Player(Game game,string name);
        ~Player();
        virtual void income();
        virtual void foreign_aid();
        virtual void coup(Player player);
        virtual string role();
        virtual string coins();
    };
}
