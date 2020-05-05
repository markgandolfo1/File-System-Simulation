#pragma once

// TextFile declaration goes here
#include "AbstractFile.h"

class TextFile : public AbstractFile {
public:
	TextFile(std::string i) {
		name = i;
	}
	//outputs contents into vector
	virtual vector<char> read();
	//asssignes member variable to parameter given
	virtual int write(std::vector<char> i);
	//appends to end of vector of contents
	virtual int append(std::vector<char> i);
	virtual unsigned int getSize();
	virtual std::string getName();
	//calls informaation to be outputted
	virtual void accept(AbstractFileVisitor*);
	//makes deep copy
	virtual AbstractFile* clone(string s);
private:
	std::vector<char> contents;
	std::string name;
};
//#endif