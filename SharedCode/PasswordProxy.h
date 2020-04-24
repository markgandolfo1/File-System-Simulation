#pragma once

#include "AbstractFile.h"
class PasswordProxy: public AbstractFile {
public:
	PasswordProxy(AbstractFile* f, string name): file(f), pass(name){}
	~PasswordProxy();
	virtual vector<char> read();
	virtual int write(std::vector<char> i);
	virtual int append(std::vector<char> i);
	virtual unsigned int getSize();
	virtual std::string getName();
	virtual void accept(AbstractFileVisitor*);
protected:
	string passwordPrompt();
private:
	bool match(string s);
	AbstractFile* file;
	string pass;

};

enum badpass{ invalidpassword};