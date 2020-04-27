// Studio21.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <string>

#include "../../SharedCode/TouchCommand.h"
#include "../../SharedCode/CommandPrompt.h"
#include "../../SharedCode/LSCommand.h"

using namespace std;

int main()
{
	SimpleFileSystem* sys = new SimpleFileSystem();
	SimpleFileFactory* fact = new SimpleFileFactory();
	TouchCommand* touch = new TouchCommand(sys,fact);
	LSCommand* ls = new LSCommand(sys);
	CommandPrompt* com = new CommandPrompt();
	com->setFileSystem(sys);
	com->setFileFactory(fact);
	com->addCommand("touch",touch);
	com->addCommand("ls", ls);
	com->run();
}
