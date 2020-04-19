#pragma once
// TextFile declaration goes here
#include "AbstractFile.h"

class TextFile : public AbstractFile {
public:
	TextFile(std::string i) {
		name = i;
	}
	vritual void read();
	virtual int write(std::vector<char> i);
	virtual int append(std::vector<char> i);
	virtual unsigned int getSize();
	virtual std::string getName();
private:
	std::vector<char> contents;
	std::string name;
};