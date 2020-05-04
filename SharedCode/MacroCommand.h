//declares macro command which can be used to create a new command from the already given commands. very expandable
#pragma once
#include "AbstractCommand.h"
#include <vector>
#include <iostream>
#include "AbstractParsingStrategy.h"
#include "AbstractFileSystem.h"
//inherits from abstract commands
class MacroCommand : public AbstractCommand {
private:

	AbstractFileSystem* filesys;
	//vector of commands stored to keep track of which commands will be used
	vector<AbstractCommand*> cmds;
	//stores what parsing strategy is used to parse what commands will be used in new one that is being created
	AbstractParsingStrategy* aps;
public:
	MacroCommand(AbstractFileSystem*);
	//sets aps variable
	void setParseStrategy(AbstractParsingStrategy*);
	//adds command to the vector
	void addCommand(AbstractCommand*);
	virtual void displayInfo();
	virtual int execute(std::string);
};