#pragma once
#include "AbstractParsingStrategy.h"
#include <sstream>
#include <iostream>

class TouchCatParsingStrategy : public AbstractParsingStrategy {
public:
	virtual vector<string> parse(string);
};