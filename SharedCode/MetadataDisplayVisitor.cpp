// definitions of metadata visitor here

#include "MetadataDisplayVisitor.h"

using namespace std;

void MetadataDisplayVisitor::visit_TextFile(TextFile* tf) {
	cout << tf->getName();
	for (int i = (int)((tf->getName()).size()); i < space; i++) {
		cout << " ";
	}

	cout << "text";
	for (int i = 0; i < mdvspace; i++) {
		cout << " ";
	}
	cout << tf->getSize();
}

void MetadataDisplayVisitor::visit_ImageFile(ImageFile* imf) {
	cout << imf->getName();
	for (int i = (int)((imf->getName()).size()); i < space; i++) {
		cout << " ";
	}

	cout << "image";
	for (int i = 0; i < mdvspace; i++) {
		cout << " ";
	}
	cout << imf->getSize();
}