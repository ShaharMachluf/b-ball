#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Game.hpp"
#include "Legue.hpp"

namespace ariel{
    class Schedule{
        std::vector<Game*> games;
        public:
        Schedule(Legue const &legue);
        std::vector<Game*> get_games() const;
        ~Schedule();
    };
}
