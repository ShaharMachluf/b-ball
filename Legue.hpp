#include <iostream>
#include <string>
#include <vector>
#include "Team.hpp"

namespace ariel{
    class Legue{
        std::vector <Team*> teams;
        public:
        Legue(std::vector <Team*> vec);
        Legue();
        Team& generate_team(int num);
        std::vector<Team*> get_teams();
    };
}