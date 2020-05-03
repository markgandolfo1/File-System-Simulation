// Studio19.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "../../SharedCode/BasicDisplayVisitor.h"
#include "../../SharedCode/PasswordProxy.h"

using namespace std;

int main()
{

	TextFile* tf = new TextFile("test");
	vector<char> ex;
	ex.push_back('1');
	tf->append(ex);
	vector<char> mod = tf->read();
	for (int i = 0; i < mod.size(); i++) {
		cout << mod[i] << endl;
	}
	mod.push_back('2');
	tf->write(mod);
	mod = tf->read();
	for (int i = 0; i < mod.size(); i++) {
		cout << mod[i] << endl;
	}

	ImageFile* img = new ImageFile("imgtest");
	BasicDisplayVisitor* basic = new BasicDisplayVisitor();
	tf->accept(basic);
	img->accept(basic);

	AbstractFile* a = new TextFile("test");
	PasswordProxy* b = new PasswordProxy(a, "pass");
	vector<char> i = { 't', 'e', 's', 't' };
	b->write(i);
	AbstractFileVisitor* f = new BasicDisplayVisitor();
	b->accept(f);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
