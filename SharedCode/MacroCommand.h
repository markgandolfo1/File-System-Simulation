#pragma once
#include "AbstractCommand.h"
#include <vector>
class AbstractParsingStrategy;

class MacroCommand : public AbstractCommand {
private:
	vector<AbstractCommand> cmds;
	AbstractParsingStrategy* aps;
public:
	virtual void displayInfo();
	virtual int execute(std::string);
};