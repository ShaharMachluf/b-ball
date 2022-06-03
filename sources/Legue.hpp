#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Team.hpp"

namespace ariel{
    class Legue{
        std::vector <Team*> teams;
        Team *temp;
        public:
        Legue(std::vector <Team*> vec);//generate only some of the team or not at all
        Legue();//generate the whole team
        void generate_team(unsigned int num);
        std::vector<Team*> get_teams();
    };
}