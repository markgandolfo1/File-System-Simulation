#pragma once
// Image file class declaration here
#include "AbstractFile.h"
class ImageFile : public AbstractFile {
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

private:
	string name;
	vector<char> contents;
	char size;
};
