#include <iostream>
#include <string>
#include <vector>
#include "sources/Team.hpp"
#include "sources/Game.hpp"
#include "sources/Legue.hpp"
#include "sources/Schedule.hpp"
#include "sources/Stats.hpp"

using namespace std;
using namespace ariel;

int main(){
    int choice = 0;
    vector<Team*> myTeams;
    //creating legue
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
    Stats stats{legue, sche};//generating stats

    cout<<"Teams ordered by wins:"<<endl;
    vector<Team*> by_wins = stats.get_by_wins();
    for(unsigned int i=0; i<by_wins.size(); ++i){
        cout<<*by_wins.at(i)<<endl;
    }

    cout<<"\nTeams ordered by difference between points shot and points taken"<<endl;
    vector<Team*> by_shoots = stats.get_by_shoots();
    for(unsigned int i=0; i<by_shoots.size(); ++i){
        cout<<*by_shoots.at(i)<<endl;
    }

    while(true){
        cout<<"\nchoose the statistic that you want to see:"<<endl;
        cout<<"to see the leading teams press '1'"<<endl;
        cout<<"to see the longest winning sequence press '2'"<<endl;
        cout<<"to see the longest losing sequence press '3'"<<endl;
        cout<<"to see how many teams shot more buskets than received press '4'"<<endl;
        cout<<"to see how many games won by teams played at home press '5'"<<endl;
        cout<<"to see how many games won by teams played out press '6'"<<endl;
        cin>>choice;
        if(choice == 1){
            cout<<"how many leading teams do you want to see?"<<endl;
            cin>>choice;
            try{
                vector<Team*> leads = stats.get_leads(choice);
                for(unsigned int i=0; i<leads.size(); ++i){
                    cout<<*leads.at(i)<<endl;
                }
            }
            catch(const char* e){
                cout<<e<<endl;
                continue;
            }
        }
        else if(choice == 2){
            cout<<"longest winning sequence: "<<stats.win_seq()<<endl;
        }
        else if(choice == 3){
            cout<<"longest losing sequence: "<<stats.loss_seq()<<endl;
        }
        else if(choice == 4){
            cout<<stats.more_shots()<<" teams shot more shots than they recieved"<<endl;
        }
        else if(choice == 5){
            cout<<stats.won_at_home()<<" games won by teams played at home"<<endl;
        }
        else if(choice == 6){
            cout<<stats.won_out()<<" games won by teams played outside games"<<endl;
        }
        else{
            cout<<"Not an option"<<endl;
        }
    }
    return 0;
}