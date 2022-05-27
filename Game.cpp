#include <iostream>
#include <string>
#include "Team.hpp"
#include "Game.hpp"

using namespace std;

namespace ariel{
    Game::Game(Team &h, Team& o){
        this->house = &h;
        this->out = &o;
    }
    Team& Game::winner(){
        return(this->house_p > this->out_p ? *house : *out);
    }
}