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