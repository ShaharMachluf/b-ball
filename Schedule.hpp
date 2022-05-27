#include <iostream>
#include <string>
#include <vector>
#include "Game.hpp"
#include "Team.hpp"
#include "Legue.hpp"

namespace ariel{
    class Schedule{
        std::vector<Game*> games;
        public:
        Schedule(Legue legue);
        std::vector<Game*> get_games();
    };
}
