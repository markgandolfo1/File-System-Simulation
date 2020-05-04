//declares copy command which is used to make a new deep copy of inputed file with a new name
#pragma once
#include "AbstractCommand.h"
#include "SimpleFileSystem.h"
#include "SimpleFileFactory.h"

#include <sstream>
//inherits from abstract command
class CopyCommand : public AbstractCommand {
private:
	//has abstracfilesystem as a member variable to keep track of files 
	AbstractFileSystem* filesys;


public:
	CopyCommand(AbstractFileSystem*);
	virtual void displayInfo();
	virtual int execute(std::string);
};
