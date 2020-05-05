//declares parsing strategy for touch cat macro command
#pragma once
#include "AbstractParsingStrategy.h"
#include <sstream>
#include <iostream>

class TouchCatParsingStrategy : public AbstractParsingStrategy {
public:
	//parses input string for touch and cat commmands respectively
	virtual vector<string> parse(string);
};