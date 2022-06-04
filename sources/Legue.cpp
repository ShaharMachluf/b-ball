#include <iostream>
#include <string>
#include <vector>
#include <random>
#include "Legue.hpp"

using namespace std;
constexpr int team_count = 20;

namespace ariel{
    Legue::Legue(const std::vector <Team*> &vec){
        if(vec.size() > team_count){
            throw("there are only 20 teams in a legue");
        }
        for(unsigned int i=0; i<vec.size()-1; ++i){
            for(unsigned int j = i+1; j<vec.size(); ++j){
                if(*vec.at(i) == *vec.at(j)){
                    throw("all teams must have different names");
                }
            }
        }
        if(vec.size() == team_count){//received 20 teams 
            this->teams = vec;
        }else{//received less than 20 teams and need to generate the rest
            unsigned int i=0;
            while(i < vec.size()){//enter the teams I received 
                this->teams.push_back(vec.at(i)); 
                ++i;
            }
            while(i < team_count){//generate the rest
                this->generate_team(i);
                this->teams.push_back(temp);
                ++i;
            }
        }
        temp = vec.at(0);
    }

    Legue::Legue(){
        for(unsigned int i=0; i < team_count; ++i){
            this->generate_team(i);
            this->teams.push_back(temp);
        }
        temp = this->teams.at(0);
    }

    void Legue::generate_team(unsigned int num){
        //pick the team's talent uniformly at random between 0 and 1
        const double lower_bound = 0;
        const double upper_bound = 1;
        std::uniform_real_distribution<double> unif(lower_bound,upper_bound);
        std::default_random_engine re;
        double a_random_double = unif(re);
        Team curr {to_string(num), a_random_double};
        temp = &curr;
    }
    
    std::vector<Team*> Legue::get_teams() const{
        return this->teams;
    }

    // Legue::~Legue(){
    //     for(unsigned int i=0; i<this->teams.size(); ++i){
    //         delete this->teams.at(i);
    //     }
    // }
}