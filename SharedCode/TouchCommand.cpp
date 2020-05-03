#include "TouchCommand.h"

TouchCommand::TouchCommand(AbstractFileSystem* a, AbstractFileFactory* b) {
	filesys = a;
	filefact = b;
}

void TouchCommand::displayInfo() {
	cout << "touch is responsible for creating a file and can be invoked using this command: touch <filename>" << endl;
}

int TouchCommand::execute(std::string s) {
	size_t find = s.find(" ");
	//one word
	if (find == string::npos) {

		AbstractFile* file = filefact->createFile(s);
		int result = success;
		if (file != 0) {
			result = filesys->addFile(s, file);
			if (result != success) {
				delete file;
			}
		}
		else {
			return couldnotcreate;
		}
		return result;
	}
	else {
		istringstream ss(s);
		string first;
		ss >> first;
		string second;
		ss >> second;
		if (second == "-p") {
			string pass;
			cout << "Whats the password?" << endl;
			cin >> pass;
			AbstractFile* filep = filefact->createFile(first);
			int r = success;
			if (filep != 0) {
				AbstractFile* p = new PasswordProxy(filep, pass);
				r = filesys->addFile(first, p);
				if (r != success) {
					delete filep;
				}
				else {
					return r;
				}
			}
			else {
				return couldnotcreate;
			}
			return r;
		}
		else {
			return couldnotcreate;
		}



	}
}