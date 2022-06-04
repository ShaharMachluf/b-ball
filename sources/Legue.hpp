#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Team.hpp"

namespace ariel{
    class Legue{
        std::vector <Team*> teams;
        Team *temp;
        void generate_team(unsigned int num);
        public:
        Legue(const std::vector <Team*> &vec);//generate only some of the team or not at all
        Legue();//generate the whole team
        std::vector<Team*> get_teams() const;
        // ~Legue();
    };
}