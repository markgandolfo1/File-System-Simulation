#pragma once
//declares password proxy class that is used to make a file password protected
#include "AbstractFile.h"
//inherits from abstract file
class PasswordProxy: public AbstractFile {
public:
	//constructor sets file and password for the file
	PasswordProxy(AbstractFile* f, string name): file(f), pass(name){}
	~PasswordProxy();
	virtual vector<char> read();
	
	virtual int write(std::vector<char> i);
	virtual int append(std::vector<char> i);
	virtual unsigned int getSize();
	virtual std::string getName();
	virtual void accept(AbstractFileVisitor*);
	//creates a deep copy with a new name
	virtual AbstractFile* clone(string s);
protected:
	//prompts user for password
	string passwordPrompt();
private:
	//tests if password given matches password 
	bool match(string s);
	AbstractFile* file;
	string pass;

};

enum badpass{ invalidpassword};