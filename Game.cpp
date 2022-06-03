#include <iostream>
#include <string>
#include <random>
#include <cmath>
#include "Team.hpp"
#include "Game.hpp"

using namespace std;

constexpr int BONUS = 10;
constexpr int min_h = 55;
constexpr int min_o = 50;
constexpr int max_p = 100;

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
        this->house->set_p_shot(this->house_p);
        this->house->set_p_taken(this->out_p);
        this->out->set_p_shot(this->out_p);
        this->out->set_p_taken(this->house_p);
    }

    int Game::set_points(int min, int max){
        double E = (min + max)/2; //mean
        double Var = (max - min)/6; //standart deviation
        std::random_device rd{};
        std::mt19937 gen{rd()};
        // values near the mean are the most likely
        // standard deviation affects the dispersion of generated values from the mean
        std::normal_distribution<> d{E,Var};
        return std::round(d(gen));
    }

    int Game::get_points(string team){
        if(team == "house"){
            return house_p;
        }else if(team == "out"){
            return out_p;
        }else{
            throw("not a valid team");
        }
    }

    Team& Game::winner(){
        if(this->house_p > this->out_p){
            this->house->add_win();
            this->out->add_loss();
            return *this->house;
        }else{
            this->out->add_win();
            this->house->add_loss();
            return *this->out;
        }
    }

    Team& Game::loser(){
        if(*this->house == this->winner()){
            return *this->out;
        }else{
            return *this->house;
        }
    }

    Team& Game::get_house(){
        return *this->house;
    }

    Team& Game::get_out(){
        return *this->out;
    }
}