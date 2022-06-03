#include <iostream>
#include <string>
#include "Team.hpp"

namespace ariel{
    class Game{
        Team *house;
        Team *out;
        int house_p;//house points
        int out_p;//out points
        int set_points(int min, int max);//randomly by normal distribution

        public:
        Game(Team &h, Team& o);
        int get_points(std::string team);
        Team& winner();
        Team& loser();
        Team& get_house();
        Team& get_out();
    };
}