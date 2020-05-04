#include "RenameParsingStrategy.h"

vector<string> RenameParsingStrategy::parse(string s) {
	string first;
	istringstream com(s);
	com >> first;
	string second;
	com >> second;
	second = first + " " + second;
	vector<string> ret;
	ret.push_back(second);
	ret.push_back(first);
	return ret;
}