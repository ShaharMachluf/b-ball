#include "doctest.h"
#include "sources/Team.hpp"
#include "sources/Game.hpp"
#include "sources/Legue.hpp"
#include "sources/Schedule.hpp"
#include "sources/Stats.hpp"

using namespace ariel;

#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}

TEST_CASE("Team"){
	//bad cases
	CHECK_THROWS((Team{"", 0.2}));
	CHECK_THROWS((Team{"macabi", -3}));
	CHECK_THROWS((Team{"hapoel", 2}));
	//good case
	Team lakers{"Lakers", 0.4};
	CHECK(lakers.get_talent() == 0.4);
	for(unsigned int i=0; i<4; ++i){//add 4 wins
		lakers.add_win();
	}
	CHECK(lakers.get_wins() == 4);
	lakers.add_win();//wins doesn't zero out
	CHECK(lakers.get_wins() == 5);
	for(unsigned int i=0; i<6; ++i){//add 6 losses
		lakers.add_loss();
	}
	CHECK(lakers.get_losses() == 6);
	lakers.add_loss();//losses doesn't zero out
	CHECK(lakers.get_losses() == 7);
	lakers.set_p_shot(7);
	CHECK(lakers.get_p_shot() == 7);
	lakers.set_p_shot(10);//p_shot doesn't zero out
	CHECK(lakers.get_p_shot() == 17);
	lakers.set_p_taken(12);
	CHECK(lakers.get_p_taken() == 12);
	lakers.set_p_taken(8);//p_taken doesn't zero out
	CHECK(lakers.get_p_taken() == 20);
	Team lakers2{"Lakers", 0.4};
	CHECK(lakers == lakers2);//operator ==
	Team not_lakers{"not", 0.56};
	CHECK(lakers != not_lakers);//operator !=
}

TEST_CASE("Game"){
	Team lakers{"Lakers", 0.4};
	Team not_lakers{"not", 0.56};
	Game game{lakers, not_lakers};
	int house_points = game.get_points("house");
	CHECK((house_points > 55 && house_points < 100));//the normal distribution works as it should
	int out_points = game.get_points("out");
	CHECK((out_points > 60 && out_points < 110));//the normal distribution works as it should and out gets 10 bonus points
	CHECK_THROWS(game.get_points("dtjh"));
	CHECK(game.winner() != game.loser());//have one winner and one loser
	CHECK(game.get_house() == lakers);
	CHECK(game.get_out() == not_lakers);
}

TEST_CASE("Legue"){
	//try to create a legue with too many teams
	Team* temp;
	vector<Team*> too_much;
	for(unsigned int i=0; i<21; i++){
		Team curr {to_string(i), 0.2};
		temp = &curr;
		too_much.push_back(temp);
	}
	CHECK_THROWS((Legue{too_much}));
	//try to create a legue with two teams that has the same name
	Team lakers{"Lakers", 0.4};
	Team lakers2{"Lakers", 0.5};
	vector<Team*> not_valid{&lakers, &lakers2};
	CHECK_THROWS((Legue{not_valid}));
	//generate a whole legue
	Legue l1;
	CHECK(l1.get_teams().size() == 20);
	//generate some of the legue
	Legue l2{vector<Team*>{&lakers}};
	CHECK(l2.get_teams().size() == 20);
	//get a full legue
	vector<Team*> myTeams;
    myTeams.push_back(new Team("Golden State Warriors", 1));
    myTeams.push_back(new Team("Boston Celtics", 0.4));
    myTeams.push_back(new Team("Brooklyn Nets", 0.5));
    myTeams.push_back(new Team("Denver Nuggets", 0.3));
    myTeams.push_back(new Team("Philadelphia 76ers", 0.4));
    myTeams.push_back(new Team("Minnesota Timberwolves", 0.5));
    myTeams.push_back(new Team("Chicago Bulls", 0.3));
    myTeams.push_back(new Team("Portland Trail Blazers", 0.2));
    myTeams.push_back(new Team("LA Clippers", 0.5));
    myTeams.push_back(new Team("Los Angeles Lakers", 1));
    myTeams.push_back(new Team("Milwaukee Bucks", 0.7));
    myTeams.push_back(new Team("Atlanta Hawks", 0.3));
    myTeams.push_back(new Team("Charlotte Hornets", 0.2));
    myTeams.push_back(new Team("Miami Heat", 0.6));
    myTeams.push_back(new Team("Phoenix Suns", 0.8));
    myTeams.push_back(new Team("Dallas Mavericks", 0.6));
    myTeams.push_back(new Team("Memphis Grizzlies", 0.5));
    myTeams.push_back(new Team("Utah Jazz", 0.3));
    myTeams.push_back(new Team("Washington Wizards", 0));
    myTeams.push_back(new Team("Oklahoma City Thunder", 0.1));
	CHECK_NOTHROW(Legue{myTeams});
	for(unsigned int i=0; i<myTeams.size(); ++i){//free memory
            delete myTeams.at(i);
    }
}

TEST_CASE("Schedule"){
	vector<Team*> myTeams;
    myTeams.push_back(new Team("Golden State Warriors", 1));
    myTeams.push_back(new Team("Boston Celtics", 0.4));
    myTeams.push_back(new Team("Brooklyn Nets", 0.5));
    myTeams.push_back(new Team("Denver Nuggets", 0.3));
    myTeams.push_back(new Team("Philadelphia 76ers", 0.4));
    myTeams.push_back(new Team("Minnesota Timberwolves", 0.5));
    myTeams.push_back(new Team("Chicago Bulls", 0.3));
    myTeams.push_back(new Team("Portland Trail Blazers", 0.2));
    myTeams.push_back(new Team("LA Clippers", 0.5));
    myTeams.push_back(new Team("Los Angeles Lakers", 1));
    myTeams.push_back(new Team("Milwaukee Bucks", 0.7));
    myTeams.push_back(new Team("Atlanta Hawks", 0.3));
    myTeams.push_back(new Team("Charlotte Hornets", 0.2));
    myTeams.push_back(new Team("Miami Heat", 0.6));
    myTeams.push_back(new Team("Phoenix Suns", 0.8));
    myTeams.push_back(new Team("Dallas Mavericks", 0.6));
    myTeams.push_back(new Team("Memphis Grizzlies", 0.5));
    myTeams.push_back(new Team("Utah Jazz", 0.3));
    myTeams.push_back(new Team("Washington Wizards", 0));
    myTeams.push_back(new Team("Oklahoma City Thunder", 0.1));
	Legue legue{myTeams};
	Schedule sche{legue};
	vector<Game*> games = sche.get_games();
	CHECK(games.size() == 380);//the number of games: 20(teams)*(19(house games)+19(out games))/2(each game is played by 2 teams)
	for(unsigned int i=0; i<myTeams.size(); ++i){
		int count = 0;
		for(unsigned int j = 0; j<games.size(); ++j){
			if(games.at(j)->get_house() == *myTeams.at(i) || games.at(j)->get_out() == *myTeams.at(i)){
				count++;
			}
		}
		CHECK(count == 38);//19(house games)+19(out games)
	}
	for(unsigned int i=0; i<myTeams.size(); ++i){//free memory
            delete myTeams.at(i);
    }
}

