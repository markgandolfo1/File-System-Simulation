#pragma once
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class AbstractParsingStrategy {
public:
	virtual vector<string> parse(string) = 0;
};