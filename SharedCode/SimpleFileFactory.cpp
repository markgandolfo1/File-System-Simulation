// studio 18 - simple file factory definitions
#include "SimpleFileFactory.h"

AbstractFile* SimpleFileFactory::createFile(string s) {
	
	size_t pt = s.find(".");
	string ext = s.substr(pt + 1, pt + 3);
	if (ext == "txt") {
		TextFile i(s);
		AbstractFile* a = &i;
		return a;

	}
	if (ext == "img") {
		ImageFile i(s);
		AbstractFile* a = &i;
		return a;
	}
	
}