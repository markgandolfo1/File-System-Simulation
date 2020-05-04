#pragma once

using namespace std;

#include <map>
#include <string>
#include <iostream>
#include <sstream>

#include "AbstractCommand.h"

class AbstractFileSystem;
class AbstractFileFactory;

enum mapkeys { insertsuccess = 0, alreadyexists=1 };
enum returnkeys {quit=1};

class CommandPrompt {
private:
	map<string, AbstractCommand*> commands;
	AbstractFileSystem* fso;
	AbstractFileFactory* ffo;
public:
	CommandPrompt();
	void setFileSystem(AbstractFileSystem*);
	void setFileFactory(AbstractFileFactory*);
	int addCommand(std::string, AbstractCommand*);
	int run();
protected:
	void listCommands();
	string prompt();
};