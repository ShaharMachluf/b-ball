#include <iostream>
#include <vector>
#include <algorithm>
#include "Stats.hpp"

using namespace std;

namespace ariel{
    Stats::Stats(Legue &l, Schedule &s):legue(&l), schedule(&s){
        by_wins = this->legue->get_teams();
        by_shoots = this->legue->get_teams();
        sort(by_wins.begin(), by_wins.end(), [](Team *a, Team *b){
                return (a->get_wins()/a->get_losses()) < (b->get_wins()/b->get_losses());
            });
        sort(by_shoots.begin(), by_shoots.end(), [](Team *a, Team *b){
                return (a->get_p_shot() - a->get_p_taken()) < (b->get_p_shot() - b->get_p_taken());
            });
    }

    std::vector<Team*> Stats::get_by_wins() const{
        return this->by_wins;
    }

    std::vector<Team*> Stats::get_by_shoots() const{
        return this->by_shoots;
    }

    std::vector<Team*> Stats::get_leads(int num){
        vector<Team*> leads(this->by_wins.begin(), this->by_wins.begin()+num);
        return leads;
    }
    
    int Stats::win_seq(){
        int seq = 0;
        int temp = 0;
        vector<Team*> teams = this->legue->get_teams();
        vector<Game*> games = this->schedule->get_games();
        for(unsigned int i=0; i< teams.size(); ++i){
            Team* curr = teams.at(i);
            temp = 0;
            for(unsigned int j = 0; j<games.size(); ++j){
                (*curr == games.at(i)->winner()) ? ++temp : temp = 0;
                if(temp > seq){
                    seq = temp;
                }
            }
        }
        return seq;
    }

    int Stats::loss_seq(){
        int seq = 0;
        int temp = 0;
        vector<Team*> teams = this->legue->get_teams();
        vector<Game*> games = this->schedule->get_games();
        for(unsigned int i=0; i< teams.size(); ++i){
            Team* curr = teams.at(i);
            temp = 0;
            for(unsigned int j = 0; j<games.size(); ++j){
                (*curr == games.at(i)->loser()) ? ++temp : temp = 0;
                if(temp > seq){
                    seq = temp;
                }
            }
        }
        return seq;
    }

    int Stats::more_shots(){
        vector<Team*> teams = this->legue->get_teams();
        int num = count_if(teams.begin(), teams.end(), [](Team *t){return t->get_p_shot() > t->get_p_taken();});
        return num;
    }

    int Stats::won_at_home(){
        vector<Game*> games = this->schedule->get_games();
        int num = count_if(games.begin(), games.end(), [](Game *g){return g->winner() == g->get_house();});
        return num;
    }

    int Stats::won_out(){
        return (int)this->schedule->get_games().size() - this->won_at_home();
    }
}