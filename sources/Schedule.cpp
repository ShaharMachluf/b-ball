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
                games.push_back(new Game{*teams.at(i), *teams.at(j)});
                //switch house team with outside team
                games.push_back(new Game{*teams.at(j), *teams.at(i)});
            }
        }
    }

    vector<Game*> Schedule::get_games(){
        return this->games;
    }
}