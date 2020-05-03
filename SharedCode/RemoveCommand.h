#pragma once

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"

class RemoveCommand : public AbstractCommand {
private:
	AbstractFileSystem* filesys;
public:
	RemoveCommand(AbstractFileSystem*);
	virtual void displayInfo();
	virtual int execute(std::string);

};
