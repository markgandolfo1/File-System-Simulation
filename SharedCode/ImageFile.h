#pragma once
// Image file class declaration here
#include "AbstractFile.h"
class ImageFile : public AbstractFile {
public:
	ImageFile(string s) {
		name = s;
		size = 0;
	}
	virtual unsigned getSize();
	virtual string getName();
	virtual int write(std::vector<char> i);
	virtual  int append(std::vector<char> i);
private:
	string name;
	vector<char> contents;
	char size;
};