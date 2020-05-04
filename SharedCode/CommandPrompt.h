#pragma once

using namespace std;
//declares commandprompt class which sets up command line and exectures all commands when the commands are inputted.
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
	//map of commands stores all of the commands that can be used
	map<string, AbstractCommand*> commands;
	AbstractFileSystem* fso;
	AbstractFileFactory* ffo;
public:
	//basic constructor
	CommandPrompt();
	void setFileSystem(AbstractFileSystem*);
	void setFileFactory(AbstractFileFactory*);
	int addCommand(std::string, AbstractCommand*);
	//run loops until user quits
	int run();
protected:
	void listCommands();
	string prompt();
};