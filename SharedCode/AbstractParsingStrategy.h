#pragma once
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class AbstractParsingStrategy {
public:
	vector<string> parse(string);
};