#pragma once
using namespace std;
#include "AbstractCommand.h"
#include "SimpleFileSystem.h"
#include "SimpleFileFactory.h"

class LSCommand : public AbstractCommand {
private:
	AbstractFileSystem* filesys;
public:
	LSCommand(AbstractFileSystem*);
	virtual void displayInfo();
	virtual int execute(std::string);
};