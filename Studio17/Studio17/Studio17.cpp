// Studio17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "../../SharedCode/ImageFile.h"
int main()
{
	ImageFile i("test");
	AbstractFile* a = &i;
	vector<char> x = { 'X', ' ', 'X', ' ', 'X', ' ', 'X', ' ', 'X', '3' };
	cout << "created new text file named: " << a->getName() << endl;
	
	a->write(x);
	cout << "added image to file. here is what is in the file now" << endl;
	a->read();
	cout << "this is size: " << a->getSize() << endl;

	
	cout << "When appending item, should return 2 indicating it is an invalid function: " << a->append(x)<< endl;
	cout << "Trying to write vector that isnt formated right" << endl;
	vector<char> y = { 'j', 'u', 'l', 'i', 'a', 'n', 'X', ' ', 'X', '3' };
	a->write(y);
	cout << "this is size: " << a->getSize() << endl;
   
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
