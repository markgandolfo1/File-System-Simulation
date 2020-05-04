#include "PasswordProxy.h"

string PasswordProxy::passwordPrompt() {
	string i;
	cout << "Input a Password: ";
	cin >> i;
	return i;
}
PasswordProxy::~PasswordProxy() {
	delete file;

}
vector<char> PasswordProxy::read() {
	if (match(passwordPrompt())) {
		return file->read();
	}
	else {
		vector<char> empty;
		return empty;
	}
}
int PasswordProxy::write(vector<char> i) {
	if (match(passwordPrompt())) {
		return file->write(i);
	}
	else {
		
		return return_vals::invalid;
	}
}
int PasswordProxy::append(std::vector<char> i) {
	if (match(passwordPrompt())) {
		return file->append(i);
	}
	else {

		return return_vals::invalid;
	}
}
unsigned PasswordProxy::getSize() {
	return file->getSize();

}
string PasswordProxy::getName() {
	return file->getName();
}
void PasswordProxy::accept(AbstractFileVisitor* i) {
	if (match(passwordPrompt())) {
		return file->accept(i);
	}
}

bool PasswordProxy::match(string s) {
	if (pass.compare(s) == 0) {
		return true;
	}else{
		return false;
	}
}
AbstractFile* PasswordProxy::clone(string s) {
	if (match(passwordPrompt())) {
		return file->clone(s);
	}
}