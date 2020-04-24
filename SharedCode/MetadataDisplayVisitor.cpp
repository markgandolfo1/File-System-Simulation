// definitions of metadata visitor here

#include "MetadataDisplayVisitor.h"
//#include "TextFile.cpp"
//#include "ImageFile.h"
using namespace std;

void MetadataDisplayVisitor::visit_TextFile(TextFile* tf) {
	//cout << tf->getName();
	//cout << tf->getSize();
	cout << "text";
}

void MetadataDisplayVisitor::visit_ImageFile(ImageFile* imf) {
	//cout << imf->getName();
	//cout << imf->getSize();
	cout << "image";
}