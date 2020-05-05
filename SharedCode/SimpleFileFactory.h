#pragma once
//Declaration for simple file factory
#include "AbstractFileFactory.h"
#include "TextFile.h"
#include "ImageFile.h"
class SimpleFileFactory : public AbstractFileFactory {
public:
	//creates file with a certain type and outputs it as a pointer to an abstract file
	virtual AbstractFile* createFile(string);
};