// declares catcommand class which adds content to file on the command line. 
#pragma once
using namespace std;
#include "AbstractCommand.h"
#include "SimpleFileSystem.h"
//inherits from abstract command
class CatCommand : public AbstractCommand {
private:
	//every command has a abstract file system as a member variable to keep track of files
	AbstractFileSystem* filesys;
public:
	CatCommand(AbstractFileSystem*);
	virtual void displayInfo();
	virtual int execute(std::string);
};
