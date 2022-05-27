#include <iostream>
#include <string>
#include <vector>
#include "Game.hpp"
#include "Team.hpp"
#include "Legue.hpp"
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
                Game curr {*teams.at(j), *teams.at(i)};
                games.push_back(&curr);
            }
        }
    }

    vector<Game*> Schedule::get_games(){
        return this->games;
    }
}