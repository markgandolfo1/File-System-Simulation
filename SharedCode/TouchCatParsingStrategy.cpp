//defines parsing strategy for the touch cat macro command
#include "TouchCatParsingStrategy.h"

vector<string> TouchCatParsingStrategy::parse(string s) {
	string first;
	//string streaam to seperate input stream by word
	istringstream com(s);
	vector<string> ret;
	if (!(com >> first)) {
		ret.push_back("");
		ret.push_back("");
		return ret;
	}
	//both of the strings should be set to the first item in the input string
	ret.push_back(first);
	ret.push_back(first);
	//returns vector of strings
	return ret;
}