#include <iostream>
#include <string>
#include "Team.hpp"

using namespace std;

namespace ariel{
    Team::Team(std::string n, double t){
        if(n == ""){
            throw("team must have a name");
        }
        this->name = n;
        this->talent = t;
    }
    
    double Team::get_talent() const{
        return this->talent;
    }
}