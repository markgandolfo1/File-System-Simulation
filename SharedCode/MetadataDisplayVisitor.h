#pragma once
// declaration of MetadataDisplayVisitor here
#include "AbstractFileVisitor.h"
#include "TextFile.h"
#include "ImageFile.h"
using namespace std;

class MetadataDisplayVisitor : public AbstractFileVisitor {
	virtual void visit_TextFile(TextFile*);
	virtual void visit_ImageFile(ImageFile*);
};