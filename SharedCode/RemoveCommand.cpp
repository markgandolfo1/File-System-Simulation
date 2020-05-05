//responsible for defining remove command methods

#include "RemoveCommand.h"

RemoveCommand::RemoveCommand(AbstractFileSystem* a){
	filesys = a;
}

void RemoveCommand::displayInfo() {
	cout << "remove is responsible for removing a file and can be invoked using this command: rm <filename>" << endl;
}

int RemoveCommand::execute(std::string s) {
	//deletes file:
	int result = filesys->deleteFile(s);
	//checks to make sure it has actually been deleted:
	if (result != executed) {
		return error;
	}
	return result;
}