#include "RemoveCommand.h"

RemoveCommand::RemoveCommand(AbstractFileSystem* a){
	filesys = a;
}

void RemoveCommand::displayInfo() {
	cout << "remove is responsible for removing a file and can be invoked using this command: rm <filename>" << endl;
}

int RemoveCommand::execute(std::string s) {
	int result = filesys->deleteFile(s);
	return result;
}