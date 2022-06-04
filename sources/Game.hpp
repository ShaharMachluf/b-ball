#pragma once
#include <iostream>
#include <string>
#include "Team.hpp"


namespace ariel{
    class Game{
        Team *house;
        Team *out;
        int house_p;//house points
        int out_p;//out points
        static int set_points(double min, double max);//randomly by normal distribution

        public:
        Game(Team &h, Team& o);
        int get_points(std::string const &team) const;
        Team& winner() const;
        Team& loser() const;
        Team& get_house() const;
        Team& get_out() const;
    };
}