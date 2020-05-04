//declares display command that is used to display contents of file on the command line
#pragma once
#include "AbstractCommand.h"
#include "SimpleFileSystem.h"
#include "SimpleFileFactory.h"
#include "PasswordProxy.h"
#include "BasicDisplayVisitor.h"
#include <sstream>
//inherits from abstract command
class DisplayCommand : public AbstractCommand {
private:
	//takes abstract file system as a member variable to keep track of files
	AbstractFileSystem* filesys;

public:
	//constructor
	DisplayCommand(AbstractFileSystem*);
	//usage message
	virtual void displayInfo();
	//runs command
	virtual int execute(std::string);
};
