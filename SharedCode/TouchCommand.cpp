#include "TouchCommand.h"

TouchCommand::TouchCommand(AbstractFileSystem* a, AbstractFileFactory* b) {
	filesys = a;
	filefact = b;
}

void TouchCommand::displayInfo() {
	cout << "touch is responsible for creating a file and can be invoked using this command: touch <filename>" << endl;
}

int TouchCommand::execute(std::string s) {
	AbstractFile* file = filefact->createFile(s);
	int result = success;
	if (file != 0) {
		result = filesys->addFile(s,file);
		if (result != success) {
			delete file;
		}
	}
	else {
		return couldnotcreate;
	}
	return result;
}