//// studio 18 - simple file factory definitions
#include "SimpleFileFactory.h"
//
AbstractFile* SimpleFileFactory::createFile(string s) {
	//finds what type of extension 
	size_t pt = s.find(".");
	string ext = s.substr(pt + 1, pt + 3);
	//creates file based on what extenstion
	if (ext == "txt") {
		AbstractFile* a = new TextFile(s);
		return a;
	}
	if (ext == "img") {
		AbstractFile* a = new ImageFile(s);
		return a;

	}
	//can add more file types with more if statements
	return nullptr;
	
}
