//declares parsing strategy class. parses input from macro commands to individual command strings. 
#pragma once
#include <vector>
#include <string>
#include <sstream>

using namespace std;
//inherited by different parsing strategy
class AbstractParsingStrategy {
public:
	virtual vector<string> parse(string) = 0;
};