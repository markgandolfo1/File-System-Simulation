#pragma once
// declaration of MetadataDisplayVisitor here
#include "AbstractFileVisitor.h"
using namespace std;

class MetadataDisplayVisitor : public AbstractFileVisitor {
	virtual void visit_TextFile(TextFile*);
	virtual void visit_ImageFile(ImageFile*);
};