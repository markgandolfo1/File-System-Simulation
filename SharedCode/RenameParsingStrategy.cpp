//defines parse function for the rename parsing strategy
#include "RenameParsingStrategy.h"

vector<string> RenameParsingStrategy::parse(string s) {
	string first;
	istringstream com(s);
	vector<string> ret;
	if (!(com >> first)) {
		ret.push_back("");
		ret.push_back("");
		return ret;
	}
	string second;
	if (!(com >> second)) {
		ret.push_back("");
		ret.push_back(first);
		return ret;
	}	second = first + " " + second;
	//second is both strings
	//first is only the first string
	ret.push_back(second);
	ret.push_back(first);
	//returns vector of strings to be used by rename macro
	return ret;
}