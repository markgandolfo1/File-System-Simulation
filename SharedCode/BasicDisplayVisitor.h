#pragma once
// declaration of BasicDisplayVisitor here
class TextFile;
class ImageFile;
using namespace std;

class BasicDisplayVisitor {
	virtual void visit_TextFile(TextFile*);
	virtual void visit_ImageFile(ImageFile*);
};