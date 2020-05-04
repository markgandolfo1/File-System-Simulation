#include "AbstractParsingStrategy.h"

vector<string> AbstractParsingStrategy::parse(string s) {
	vector<string> ret;
	string until = "";
	int i = 0;
	for (char c : s) {
		if (c != ' ') {
			until += c;
		}
		else {
			ret.push_back(until);
			until = "";
			i++;
		}
	}
	ret.push_back(until);
	return ret;
}