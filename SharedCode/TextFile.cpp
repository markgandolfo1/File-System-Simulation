//  Define the TextFile class here
#include "TextFile.h"
virtual void TextFile::read() {
	for (int i = 0; i < contents.size(); ++i) {
		cout << contents[i] << " " << endl;
	}
}
virtual unsigned TextFile::getSize() {
	return contents.getSize();
}
virtual std::string TextFile::getName{
	return name;
}
virtual int TexFile::write(std::vector<char> i) {
	contents = i;
	return 0;
}
virtual int TextFile::append(std::vector<char> i) {
	for (int x = 0; x < i.size(); ++x) {
		contents.push_back(i[x]);
	}
	return 0;
}

