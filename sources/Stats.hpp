#include <iostream>
#include <vector>
#include "Schedule.hpp"

namespace ariel{
    class Stats{
        Legue *legue;
        Schedule *schedule;
        std::vector <Team*> by_wins;//teams sorted by win-lose ratio
        std::vector <Team*> by_shoots;//teams sorted by diffrence between points shot and points taken
        public:
        Stats(Legue &l, Schedule &s);
        std::vector<Team*> get_by_wins() const;
        std::vector<Team*> get_by_shoots() const;
        std::vector<Team*> get_leads(int num);
        int win_seq();
        int loss_seq();
        int more_shots();//shot more baskets then recieved 
        int won_at_home();//how many games won in teams played at home
        int won_out();//how many games won in teams played out
    };
}