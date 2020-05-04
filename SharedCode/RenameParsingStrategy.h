#pragma once
#include "AbstractParsingStrategy.h"
#include <sstream>
#include <iostream>

class RenameParsingStrategy : public AbstractParsingStrategy {
public:
	virtual vector<string> parse(string);
};