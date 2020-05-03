#pragma once
using namespace std;
#include "AbstractCommand.h"
#include "SimpleFileSystem.h"

class CatCommand : public AbstractCommand {
private:
	AbstractFileSystem* filesys;
public:
	CatCommand(AbstractFileSystem*);
	virtual void displayInfo();
	virtual int execute(std::string);
};
