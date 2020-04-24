// definitions of metadata visitor here

#include "MetadataDisplayVisitor.h"
using namespace std;

void MetadataDisplayVisitor::visit_TextFile(TextFile* tf) {
	cout << "text";
}

void MetadataDisplayVisitor::visit_ImageFile(ImageFile* imf) {
	cout << "image";
}