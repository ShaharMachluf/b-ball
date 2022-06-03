#include <iostream>
#include <string>
#include <vector>
#include "Schedule.hpp"

using namespace std;
namespace ariel{
    Schedule::Schedule(Legue legue){
        vector<Team*> teams = legue.get_teams();
        for(unsigned int i=0; i < teams.size() - 1; ++i){
            for(unsigned int j = i+1; j < teams.size(); ++j){
                Game curr {*teams.at(i), *teams.at(j)};
                games.push_back(&curr);
                //switch house team with outside team
                Game curr2 {*teams.at(j), *teams.at(i)};
                games.push_back(&curr2);
            }
        }
    }

    vector<Game*> Schedule::get_games(){
        return this->games;
    }
}