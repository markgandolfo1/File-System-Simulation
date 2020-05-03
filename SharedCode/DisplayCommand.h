#pragma once
#include "AbstractCommand.h"
#include "SimpleFileSystem.h"
#include "SimpleFileFactory.h"
#include "PasswordProxy.h"
#include "BasicDisplayVisitor.h"
#include <sstream>
class DisplayCommand : public AbstractCommand {
private:
	AbstractFileSystem* filesys;

public:
	DisplayCommand(AbstractFileSystem*);
	virtual void displayInfo();
	virtual int execute(std::string);
};
