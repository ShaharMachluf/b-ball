#include <iostream>
#include <string>
#include "Team.hpp"

namespace ariel{
    class Game{
        Team *house;
        Team *out;
        int house_p;
        int out_p;
        public:
        Game(Team &h, Team& o);
        Team& winner();
    };
}