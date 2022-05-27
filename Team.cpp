#include <iostream>
#include <string>
#include "Team.hpp"

using namespace std;

namespace ariel{
    Team::Team(std::string n, double t){
        this->name = n;
        this->talent = t;
    }
    double Team::get_talent() const{
        return this->talent;
    }
}