//  Define the TextFile class here
#include "TextFile.h"
void TextFile::read() {
	for (int i = 0; i < contents.size(); ++i) {
		std::cout << contents[i] << " " << std::endl;
	} 
}
unsigned TextFile::getSize() {
	return contents.size();
}
std::string TextFile::getName(){
	return name;
}
int TextFile::write(std::vector<char> i) {
	contents = i;
	return 0;
}
int TextFile::append(std::vector<char> i) {
	for (int x = 0; x < i.size(); ++x) {
		contents.push_back(i[x]);
	}
	return 0;
}

