// definition of ImageFile class here
#include "ImageFile.h"

unsigned int ImageFile::getSize() {
	return (unsigned int)contents.size();
}

string ImageFile::getName() {
	return name;
}
int ImageFile::write(std::vector<char> i) {
	bool fail = false;
	int x = (int)i.size();
	int  s = (int)i[(__int64)x-1];
	s = s - 48;
	if ((s * s) != x - 1) {
		fail = true;
	}
	size = s;
	//iterates through the size to update the contents
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

vector<char> ImageFile::read() {
	return contents;
}

//allows visitors
void ImageFile::accept(AbstractFileVisitor* afv) {
	(afv)->visit_ImageFile(this);
}
AbstractFile* ImageFile::clone(string s) {
	string temp = name;
	name = s;
	AbstractFile* cp = new ImageFile(*this);
	name = temp;
	return cp;
}