#ifndef EX4_PARTA_AMBASSADOR_H
#define EX4_PARTA_AMBASSADOR_H

#endif //EX4_PARTA_AMBASSADOR_H

#include <string>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <vector>
#include "Player.hpp"

using namespace std;

namespace coup{
    class Ambassador : public Player{
    public:
        Ambassador(Game game,string name): Player(game,name){
            cout<<"i am ambassador";
        }
        void transfer(Player player1,Player player2);
        void block(Player player);
    };
}