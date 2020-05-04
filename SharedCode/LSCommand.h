//declaes lscommand class that is used to list all the files in the file system in the command prompt
#pragma once
using namespace std;
#include "AbstractCommand.h"
#include "SimpleFileSystem.h"
#include "SimpleFileFactory.h"
//inherits from abstract command
class LSCommand : public AbstractCommand {
private:
	//has a abstract file system as a member variable to keep track of files
	AbstractFileSystem* filesys;
public:
	//constructor 
	LSCommand(AbstractFileSystem*);
	//usage
	virtual void displayInfo();
	//executes command
	virtual int execute(std::string);
};