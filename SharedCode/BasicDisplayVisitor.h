#pragma once
// declaration of BasicDisplayVisitor here
//class TextFile;
//class ImageFile;
#include "AbstractFileVisitor.h"
#include "TextFile.h"
#include "ImageFile.h"
#include <vector>
using namespace std;

class BasicDisplayVisitor : public AbstractFileVisitor {
	virtual void visit_TextFile(TextFile*);
	virtual void visit_ImageFile(ImageFile*);
};