//declares rename parsing strategy which parses rename string into copy command and remove command
#pragma once

#include "AbstractParsingStrategy.h"
#include <sstream>
#include <iostream>
//inherits from abstracrt parsing strategy
class RenameParsingStrategy : public AbstractParsingStrategy {
public:
	//parses
	virtual vector<string> parse(string);
};