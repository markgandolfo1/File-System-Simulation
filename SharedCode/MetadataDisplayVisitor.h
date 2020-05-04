#pragma once
// declaration of MetadataDisplayVisitor which displays onto cout the metadata of a given file.
#include "AbstractFileVisitor.h"
#include "TextFile.h"
#include "ImageFile.h"
//space used for ls command to format columns. 
//mdv used to format column for type and size for ls -m
enum spaces { space = 21, mdvspace = 6 };

using namespace std;
///inherits from abstractfilevisitor
class MetadataDisplayVisitor : public AbstractFileVisitor {
	virtual void visit_TextFile(TextFile*);
	virtual void visit_ImageFile(ImageFile*);
};