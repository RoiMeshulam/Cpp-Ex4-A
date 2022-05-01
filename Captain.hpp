#ifndef EX4_PARTA_CAPTAIN_H
#define EX4_PARTA_CAPTAIN_H

#endif //EX4_PARTA_CAPTAIN_H

#include <string>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <vector>
#include "Player.hpp"

using namespace std;


namespace coup{
    class Captain : public Player{
    public:
        Captain(Game game,string name): Player(game,name){
            cout<< "captain";
        }
        void steal(Player player);
        void block(Player player);
    };
}