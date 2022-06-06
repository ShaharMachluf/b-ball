#pragma once
#include <iostream>
#include <string>

namespace ariel{
    class Team{
        std::string name;
        double talent;
        int wins;
        int losses;
        int p_shot;//points the team earned
        int p_taken;//points the team lost
        public:
        Team(std::string const &n, double t);
        double get_talent() const;
        int get_wins() const;
        void add_win();
        int get_losses() const;
        void add_loss();
        int get_p_shot() const;
        void set_p_shot(int points);
        int get_p_taken() const;
        void set_p_taken(int points);
        bool operator==(const Team &other) const;
        bool operator!=(const Team &other) const;
        std::string get_name() const;
        friend std::ostream& operator<<(std::ostream& output, const Team& other);
    };
}