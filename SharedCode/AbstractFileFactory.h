#pragma once
// studio 18 - file factory interface declared here
#include <string>
#include <iostream>
#include "AbstractFile.h"


class AbstractFileFactory {
public:
	virtual AbstractFile* createFile(string) = 0;
};