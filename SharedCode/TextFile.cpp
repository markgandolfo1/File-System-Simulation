//  Define the TextFile class here
#include "TextFile.h"
//returns contents of file
vector<char> TextFile::read() {
	return contents;
}
//gets size
unsigned int TextFile::getSize() {
	return (unsigned int)contents.size();
}
std::string TextFile::getName(){
	return name;
}
//set the contents of file to the inputed vector
int TextFile::write(std::vector<char> i) {
	contents = i;
	return 0;
}
//add inputed vector to the end of what is already in contents
int TextFile::append(std::vector<char> i) {
	for (int x = 0; x < i.size(); ++x) {
		contents.push_back(i[x]);
	}
	return 0;
}

void TextFile::accept(AbstractFileVisitor* afv) {
	(afv)->visit_TextFile(this);
}
//creates deep copy
AbstractFile* TextFile::clone(string s) {
	string temp = name;
	name = s;
	AbstractFile* cp = new TextFile(*this);
	name = temp;
	return cp;

}
