#include <iostream>
#include <string>

namespace ariel{
    class Team{
        std::string name;
        double talent;
        public:
        Team(std::string n, double t);
        double get_talent() const;
    };
}