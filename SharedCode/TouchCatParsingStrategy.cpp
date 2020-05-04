#include "TouchCatParsingStrategy.h"

vector<string> TouchCatParsingStrategy::parse(string s) {
	string first;
	istringstream com(s);
	vector<string> ret;
	if (!(com >> first)) {
		ret.push_back("");
		ret.push_back("");
		return ret;
	}
	ret.push_back(first);
	ret.push_back(first);
	return ret;
}