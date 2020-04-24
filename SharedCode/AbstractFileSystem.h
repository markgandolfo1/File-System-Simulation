#pragma once
// declaration of the interface all file systems provide goes here
#include <iostream>
#include <string>
#include "AbstractFile.h"

class AbstractFileSystem {
public:
	virtual int addFile(std::string s, AbstractFile* f) = 0;
	virtual int deleteFile(std::string s) = 0;
	virtual AbstractFile* openFile(std::string s) = 0;
	virtual int closeFile(AbstractFile* f) = 0;

};

