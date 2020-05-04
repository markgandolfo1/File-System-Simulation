#pragma once
#include "AbstractCommand.h"
#include <vector>
#include <iostream>
#include "AbstractParsingStrategy.h"
#include "AbstractFileSystem.h"

class MacroCommand : public AbstractCommand {
private:
	AbstractFileSystem* filesys;
	vector<AbstractCommand*> cmds;
	AbstractParsingStrategy* aps;
public:
	MacroCommand(AbstractFileSystem*);
	void setParseStrategy(AbstractParsingStrategy*);
	void addCommand(AbstractCommand*);
	virtual void displayInfo();
	virtual int execute(std::string);
};