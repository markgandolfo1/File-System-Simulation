#pragma once
// studio 18 - file factory interface declared here. this creates a file from a string and returns it.
#include <string>
#include <iostream>
#include "AbstractFile.h"
///this is a seperate class for expandability convenience.

class AbstractFileFactory {
public:
	virtual AbstractFile* createFile(string) = 0;
};