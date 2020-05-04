//  Define the TextFile class here
#include "TextFile.h"
//#include "AbstractFileVisitor.h"
vector<char> TextFile::read() {
	return contents;
	//for (int i = 0; i < contents.size(); ++i) {
	//	std::cout << contents[i];
	//} 
}
unsigned int TextFile::getSize() {
	return (unsigned int)contents.size();
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

void TextFile::accept(AbstractFileVisitor* afv) {
	(afv)->visit_TextFile(this);
}
AbstractFile* TextFile::clone(string s) {
	string temp = name;
	name = s;
	AbstractFile* cp = new TextFile(*this);
	name = temp;
	return cp;

}
