#include <iostream>
#include <string>
#include <vector>
#include "Team.hpp"

namespace ariel{
    class Legue{
        std::vector <Team*> teams;
        public:
        Legue(std::vector <Team*> vec);//generate only some of the team or not at all
        Legue();//generate the whole team
        Team& generate_team(int num);
        std::vector<Team*> get_teams();
    };
}