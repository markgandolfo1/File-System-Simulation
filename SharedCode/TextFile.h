#pragma once

// TextFile declaration goes here
#include "AbstractFile.h"

class TextFile : public AbstractFile {
public:
	TextFile(std::string i) {
		name = i;
	}
	virtual vector<char> read();
	virtual int write(std::vector<char> i);
	virtual int append(std::vector<char> i);
	virtual unsigned int getSize();
	virtual std::string getName();
	virtual void accept(AbstractFileVisitor*);
	virtual AbstractFile* clone(string s);
private:
	std::vector<char> contents;
	std::string name;
};
//#endif