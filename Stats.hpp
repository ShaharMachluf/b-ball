#include <iostream>
#include <vector>
#include "Legue.hpp"
#include "Schedule.hpp"

namespace ariel{
    class Stats{
        Legue *legue;
        Schedule *schedule;
        std::vector <Team*> by_wins;//teams sorted by win-lose ratio
        std::vector <Team*> by_shoots;//teams sorted by diffrence between points shot and points taken
        public:
        Stats(Legue &l, Schedule &s);
        std::vector<Team*> get_by_wins();
        std::vector<Team*> get_by_shoots();
        std::vector<Team*> get_leads(int num);
        int win_seq();
        int loss_seq();
        int more_shots();//shot more bascets then recieved 
        int won_at_home();//how many teams won in games played at home
        int won_out();//how many teams won in games played out
    };
}