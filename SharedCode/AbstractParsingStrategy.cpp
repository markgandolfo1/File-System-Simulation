#include "AbstractParsingStrategy.h"

vector<string> AbstractParsingStrategy::parse(string s) {
	vector<string> ret;
	istringstream com(s);
	for (int i = 0; com >> ret[i]; i++);
}