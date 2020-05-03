// Studio19.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//#include "../../SharedCode/BasicDisplayVisitor.h"

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
	TouchCommand* touch = new TouchCommand(sys, fact);
	LSCommand* ls = new LSCommand(sys);
	CommandPrompt* com = new CommandPrompt();
	com->setFileSystem(sys);
	com->setFileFactory(fact);
	com->addCommand("touch", touch);
	com->addCommand("ls", ls);
	com->run();

	//Studio 19:
	//TextFile* tf = new TextFile("test");
	//vector<char> ex;
	//ex.push_back('1');
	//tf->append(ex);
	//vector<char> mod = tf->read();
	//for (int i = 0; i < mod.size(); i++) {
	//	cout << mod[i] << endl;
	//}
	//mod.push_back('2');
	//tf->write(mod);
	//mod = tf->read();
	//for (int i = 0; i < mod.size(); i++) {
	//	cout << mod[i] << endl;
	//}

	//ImageFile* img = new ImageFile("imgtest");
	//BasicDisplayVisitor* basic = new BasicDisplayVisitor();
	//tf->accept(basic);
	//img->accept(basic);
}