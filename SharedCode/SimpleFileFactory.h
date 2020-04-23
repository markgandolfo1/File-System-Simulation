#pragma once
// Studio 18 - simplefilefactory class declaration goes here
#include "AbstractFileFactory.h"
#include "TextFile.h"
#include "ImageFile.h"
class SimpleFileFactory : public AbstractFileFactory {
public:
	virtual AbstractFile* createFile(string);

}