#include <iostream>
#include <random>
#include <string>
#include <cmath>

int main(){
    double E = (50 + 100)/2;
    double Var = (100-50)/6;
    std::random_device rd{};
    std::mt19937 gen{rd()};
 
    // values near the mean are the most likely
    // standard deviation affects the dispersion of generated values from the mean
    std::normal_distribution<> d{E,Var};
 
    // std::map<int, int> hist{};
    // for(int n=0; n<10000; ++n) {
    //     ++hist[std::round(d(gen))];
    // }
    // for(auto p : hist) {
    //     std::cout << std::setw(2)
    //               << p.first << ' ' << std::string(p.second/200, '*') << '\n';
    // } 
    std::cout<<std::round(d(gen))<<std::endl;
    std::cout<<std::round(d(gen))<<std::endl;
    return 0;
}