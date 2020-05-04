#pragma once
#include "AbstractParsingStrategy.h"
#include <sstream>

class RenameParsingStrategy : public AbstractParsingStrategy {
public:
	virtual vector<string> parse(string);
};