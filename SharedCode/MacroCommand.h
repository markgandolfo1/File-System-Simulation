#pragma once
#include "AbstractCommand.h"
#include <vector>
#include <iostream>
#include "AbstractParsingStrategy.h";

class MacroCommand : public AbstractCommand {
private:
	vector<AbstractCommand*> cmds;
	AbstractParsingStrategy* aps;
public:
	//MacroCommand(vector<AbstractCommand>);
	void setParseStrategy(AbstractParsingStrategy*);
	void addCommand(AbstractCommand*);
	virtual void displayInfo();
	virtual int execute(std::string);
};