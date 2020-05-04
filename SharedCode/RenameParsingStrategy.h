#pragma once
#include "AbstractParsingStrategy.h"

class RenameParsingStrategy : public AbstractParsingStrategy {
	virtual vector<string> parse(string);
};