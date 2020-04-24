#pragma once
// declaration of BasicDisplayVisitor here
//class TextFile;
//class ImageFile;
#include "AbstractFileVisitor.h"
using namespace std;

class BasicDisplayVisitor : public AbstractFileVisitor {
	virtual void visit_TextFile(TextFile*);
	virtual void visit_ImageFile(ImageFile*);
};