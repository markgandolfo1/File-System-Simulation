// definitions of basic display visitor here
#include "BasicDisplayVisitor.h"


using namespace std;

void BasicDisplayVisitor::visit_TextFile(TextFile* tf) {
	vector<char> conts = tf->read();
	//iterates through contents of text file
	for (int i = 0; i < conts.size(); ++i) {
		cout << conts[i];
	} 
}

void BasicDisplayVisitor::visit_ImageFile(ImageFile* imf) {
	unsigned int dim = (int) sqrt(imf->getSize());
	vector<char> conts = imf->read();

	for(int j = dim - 1; j >= 0; j--) {
		for (unsigned i = 0; i <= dim - 1; i++) {
			//position in the vector
			int index = (j * dim) + i;
			cout << conts[index];
		}
	cout << endl;
	}
}
