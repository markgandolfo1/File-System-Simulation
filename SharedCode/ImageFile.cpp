// definition of ImageFile class here
#include "ImageFile.h"

unsigned ImageFile::getSize() {
	return contents.size();
}
string ImageFile::getName() {
	return name;
}
int ImageFile::write(std::vector<char> i) {
	bool fail = false;
	int x = i.size();
	int  s = i[x-1];
	s = s - 48;
	if ((s * s) != x - 1) {
		fail = true;
	}
	size = s;
	for (int k = 0; k < x - 1; ++k) {
		contents.push_back(i[k]);
		if ((i[k] != 'X') && (i[k] != ' ')) {
			fail = true;
		}
	}
	if (fail == false) {
		return return_vals::success;
	}
	else {
		contents.clear();
		size = 0;
		return return_vals::invalid;
	}



}
int ImageFile::append(std::vector<char> i) {
	return return_vals::notsupported;
}

void ImageFile::read() {
	int dim = size;
	for (unsigned j = dim - 1; j < dim; j--) {
		//unsigned int will go to highest value if passed 0.
		for (unsigned i = 0; i <= dim - 1; i++) {
			int index = (j * dim) + i;

			cout << contents[index];
		}
		cout << " " << endl;
	}
}