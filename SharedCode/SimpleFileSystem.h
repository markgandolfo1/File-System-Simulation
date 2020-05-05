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
	//adds file to system
	virtual int addFile(string s, AbstractFile* f);
	//adds to set of open files
	virtual AbstractFile* openFile(std::string s);
	//removes from set
	virtual int closeFile(AbstractFile* f);
	//deletes from map
	virtual int deleteFile(std::string s);
	virtual std::set<string> getFileNames();
private:
	map<string, AbstractFile*> files;
	set<AbstractFile*> openFiles;

};
