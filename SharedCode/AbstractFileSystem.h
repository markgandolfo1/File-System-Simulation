#pragma once
// declaration of the interface all file systems provide goes here
#include <iostream>
#include <string>
#include "AbstractFile.h"
#include <set>
#include <map>
//enums for the file systems
enum create {created, couldnotcreate};
//each file system inherits this
class AbstractFileSystem {
public:
	virtual int addFile(std::string s, AbstractFile* f) = 0;
	virtual int deleteFile(std::string s) = 0;
	virtual AbstractFile* openFile(std::string s) = 0;
	virtual int closeFile(AbstractFile* f) = 0;
	virtual std::set<string> getFileNames() = 0;
};

