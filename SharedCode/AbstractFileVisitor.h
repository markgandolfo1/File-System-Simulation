#pragma once
// declaration of the file visitor interface here

//#include "TextFile.h"
//#include "ImageFile.h"
class TextFile;
class ImageFile;
#include <iostream>

using namespace std;

class AbstractFileVisitor {
public:
	virtual void visit_TextFile(TextFile*) = 0;
	virtual void visit_ImageFile(ImageFile*) = 0;
};