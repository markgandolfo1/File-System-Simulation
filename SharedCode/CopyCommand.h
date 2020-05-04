#pragma once
#include "AbstractCommand.h"
#include "SimpleFileSystem.h"
#include "SimpleFileFactory.h"

#include <sstream>
class CopyCommand : public AbstractCommand {
private:
	AbstractFileSystem* filesys;
	AbstractFileFactory* filefact;

public:
	CopyCommand(AbstractFileSystem*);
	virtual void displayInfo();
	virtual int execute(std::string);
};