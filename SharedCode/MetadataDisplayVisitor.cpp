// definitions of metadata visitor here

#include "MetadataDisplayVisitor.h"
//#include "TextFile.cpp"
//#include "ImageFile.h"
using namespace std;

void MetadataDisplayVisitor::visit_TextFile(TextFile* tf) {
	//Studio:
	//cout << tf->getName() << endl;
	//cout << tf->getSize() << endl;
	//cout << "text" << endl;
	cout << "text";
	for (int i = 0; i < mdvspace; i++) {
		cout << " ";
	}
	cout << tf->getSize();
}

void MetadataDisplayVisitor::visit_ImageFile(ImageFile* imf) {
	//Studio:
	//cout << imf->getName() << endl;
	//cout << imf->getSize() << endl;
	//cout << "image" << endl;
	cout << "image";
	for (int i = 0; i < mdvspace-1; i++) {
		cout << " ";
	}
	cout << imf->getSize();
}