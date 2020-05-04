#pragma once
// declaration of the file visitor interface here


class TextFile;
class ImageFile;
#include <iostream>

using namespace std;
//used to print out to cout
class AbstractFileVisitor {
public:
	//called from accept from an abstract type of file
	virtual void visit_TextFile(TextFile*) = 0;
	virtual void visit_ImageFile(ImageFile*) = 0;
};