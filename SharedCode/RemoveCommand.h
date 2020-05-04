//declares the remove command which is used to remove files from the file system in the command prompt
#pragma once

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
//inherits from abstractcommand
class RemoveCommand : public AbstractCommand {
private:
	AbstractFileSystem* filesys;
public:
	//constructor
	RemoveCommand(AbstractFileSystem*);
	//usage
	virtual void displayInfo();
	//executes command
	virtual int execute(std::string);

};
