#include <string>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <vector>
//#include "Player.hpp"
#include "Game.hpp"

using namespace std;

namespace coup{
    Game::Game() {}
    Game::~Game(){}
    string Game::turn(){
        return "hi";
    }
    vector<string> Game::players(){
        vector<string> ans;
        return ans;
    }
    string Game::winner(){
        return "roi";
    }
}