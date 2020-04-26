#pragma once
#include "AbstractCommand.h"
#include "SimpleFileSystem.h"
#include "SimpleFileFactory.h"

class TouchCommand : public AbstractCommand{
private:
	AbstractFileSystem* filesys;
	AbstractFileFactory* filefact;
public:
	TouchCommand(AbstractFileSystem*, AbstractFileFactory*);
	virtual void displayInfo();
	virtual int execute(std::string);
};