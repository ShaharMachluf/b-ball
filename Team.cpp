#include <iostream>
#include <string>
#include "Team.hpp"

using namespace std;

namespace ariel{
    Team::Team(std::string n, double t):wins(0), losses(0), p_shot(0), p_taken(0){
        if(n == ""){
            throw("team must have a name");
        }
        this->name = n;
        this->talent = t;
    }
    
    double Team::get_talent() const{
        return this->talent;
    }

    int Team::get_wins(){
        return this->wins;
    }

    void Team::add_win(){
        this->wins++;
    }

    int Team::get_losses(){
        return this->losses;
    }

    void Team::add_loss(){
        this->losses++;
    }

    int Team::get_p_shot(){
        return this->p_shot;
    }

    void Team::set_p_shot(int points){
        this->p_shot += points;
    }

    int Team::get_p_taken(){
        return this->p_taken;
    }

    void Team::set_p_taken(int points){
        this->p_taken += points;
    }

    bool Team::operator==(const Team &other) const{
        return this->name == other.name;
    }
    bool Team::operator!=(const Team &other) const{
        return !(*this == other);
    }
}