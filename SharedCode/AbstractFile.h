#pragma once
// declare AbstractFile here. As all methods are virtual and will not be defined, no .cpp file is necessary

#include <vector>
#include <string>
#include <iostream>
#include "AbstractFileVisitor.h"

using namespace std;
class AbstractFile {
public:
	virtual void accept(AbstractFileVisitor*) = 0;
	virtual vector<char> read() = 0;
	virtual int write(std::vector<char> i) = 0;
	virtual int append(std::vector<char> i) = 0;
	virtual unsigned int getSize() = 0;
	virtual std::string getName() = 0;
	virtual ~AbstractFile() = default;
	virtual AbstractFile* clone(string s) = 0;
};
enum return_vals { success, exists, invalid, notopen, nonexist, open, notsupported};