#pragma once
// declaration of SimpleFileSystem class goes here
#include "AbstractFileSystem.h"
#include <map>
#include <set>
#include "TextFile.h"
#include "ImageFile.h"
using namespace std;
class SimpleFileSystem : public AbstractFileSystem {
public:
	virtual int addFile(string s, AbstractFile* f);
	virtual AbstractFile* openFile(std::string s);
	virtual int closeFile(AbstractFile* f);
	virtual int deleteFile(std::string s);
private:
	map<string, AbstractFile*> files;
	set<AbstractFile*> openFiles;

};
