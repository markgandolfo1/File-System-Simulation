// definitions of basic display visitor here
#include "BasicDisplayVisitor.h"

//#include "TextFile.h"
//#include "ImageFile.h"
//#include "AbstractFile.h"
using namespace std;

void BasicDisplayVisitor::visit_TextFile(TextFile* tf) {
	vector<char> conts = tf->read();
	for (int i = 0; i < conts.size(); ++i) {
		cout << conts[i];
	} 
}

void BasicDisplayVisitor::visit_ImageFile(ImageFile* imf) {
	unsigned int dim = sqrt(imf->getSize());
	vector<char> conts = imf->read();

	for (unsigned j = dim - 1; j < dim; j--) {
		for (unsigned i = 0; i <= dim - 1; i++) {
			int index = (j * dim) + i;
			cout << conts[index];
		}
	cout << " " << endl;
	}
}
