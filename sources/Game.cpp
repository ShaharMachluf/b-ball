#include <iostream>
#include <string>
#include <random>
#include <cmath>
#include "Game.hpp"

using namespace std;

constexpr int BONUS = 10;
constexpr double min_h = 55;
constexpr double min_o = 50;
constexpr double max_p = 100;
constexpr double divide = 6;

namespace ariel{
    Game::Game(Team &h, Team& o){
        this->house = &h;
        this->out = &o;
        this->house_p = set_points(min_h, max_p);
        this->out_p = set_points(min_o, max_p);
        //give a bonus to the team with the larger talent rate
        if(this->house->get_talent() > this->out->get_talent()){
            this->house_p += BONUS;
        }
        else{
            this->out_p += BONUS;
        }
        //update the teams
        this->house->set_p_shot(this->house_p);
        this->house->set_p_taken(this->out_p);
        this->out->set_p_shot(this->out_p);
        this->out->set_p_taken(this->house_p);
    }

    int Game::set_points(double min, double max){
        double E = (min + max)/2; //mean
        double Var = (max - min)/divide; //standart deviation
        std::random_device rd{};
        std::mt19937 gen{rd()};
        // values near the mean are the most likely
        // standard deviation affects the dispersion of generated values from the mean
        std::normal_distribution<> d{E,Var};
        return static_cast<int>(std::round(d(gen)));
    }

    int Game::get_points(string const &team) const{
        if(team == "house"){
            return house_p;
        }if(team == "out"){
            return out_p;
        }
        throw("not a valid team");
    }

    Team& Game::winner() const{
        if(this->house_p > this->out_p){
            this->house->add_win();
            this->out->add_loss();
            return *this->house;
        }
        this->out->add_win();
        this->house->add_loss();
        return *this->out;
    }

    Team& Game::loser() const{
        if(*this->house == this->winner()){
            return *this->out;
        }
        return *this->house;
    }

    Team& Game::get_house() const{
        return *this->house;
    }

    Team& Game::get_out() const{
        return *this->out;
    }
}