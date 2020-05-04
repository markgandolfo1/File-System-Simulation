#pragma once
// declaration of BasicDisplayVisitor here. this prints out to cout the contents of the file

#include "AbstractFileVisitor.h"
#include "TextFile.h"
#include "ImageFile.h"
#include <vector>
using namespace std;
//inherits from abstractfile visitor
class BasicDisplayVisitor : public AbstractFileVisitor {
	//could add more when adding new file types. 
	virtual void visit_TextFile(TextFile*);
	virtual void visit_ImageFile(ImageFile*);
};