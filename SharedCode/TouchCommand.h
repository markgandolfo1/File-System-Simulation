//declares touch command which creates a new file for the system in the command prompt
#pragma once
#include "AbstractCommand.h"
#include "SimpleFileSystem.h"
#include "SimpleFileFactory.h"
#include "PasswordProxy.h"
#include <sstream>
class TouchCommand : public AbstractCommand{
private:
	AbstractFileSystem* filesys;
	AbstractFileFactory* filefact;
public:
	//constructor
	TouchCommand(AbstractFileSystem*, AbstractFileFactory*);
	//usage
	virtual void displayInfo();
	//executes command
	virtual int execute(std::string);
};