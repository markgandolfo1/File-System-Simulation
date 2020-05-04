#pragma once
#include "AbstractParsingStrategy.h"
#include <sstream>

class RenameParsingStrategy : public AbstractParsingStrategy {
	virtual vector<string> parse(string);
};