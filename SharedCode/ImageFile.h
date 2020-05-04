//creates class for image file that inherits abstract file. methods in class allows user to input and output image files 

#pragma once

#include "AbstractFile.h"
class ImageFile : public AbstractFile {
	// include these visitors as friend classes so that they can be used in the accept function when outputting data onto cout
	friend class BasicDisplayVisitor;
	friend class MetadataDisplayVisitor;
public:
	ImageFile(string s) {
		name = s;
		size = 0;
	}
	virtual unsigned int getSize();
	virtual string getName();
	virtual int write(std::vector<char> i);
	virtual int append(std::vector<char> i);
	virtual vector<char> read();
	virtual void accept(AbstractFileVisitor*);
	virtual AbstractFile* clone(string s);

private:
	//member variables are name of file, contents in a vector of chars, and size of file
	string name;
	vector<char> contents;
	char size;
};
