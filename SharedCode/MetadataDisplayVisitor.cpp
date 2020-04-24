// definitions of metadata visitor here

#include "MetadataDisplayVisitor.h"
//#include "TextFile.cpp"
//#include "ImageFile.h"
using namespace std;

void MetadataDisplayVisitor::visit_TextFile(TextFile* tf) {
	cout << tf->getName() << endl;
	cout << tf->getSize() << endl;
	cout << "text" << endl;
}

void MetadataDisplayVisitor::visit_ImageFile(ImageFile* imf) {
	cout << imf->getName() << endl;
	cout << imf->getSize() << endl;
	cout << "image" << endl;
}