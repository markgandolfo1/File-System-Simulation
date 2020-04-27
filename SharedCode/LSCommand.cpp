#include "LSCommand.h"

LSCommand::LSCommand(AbstractFileSystem* a) {
	filesys = a;
}

void LSCommand::displayInfo() {
	cout << "ls is responsible for outputting the names of the files in the file system and can be invoked using this command: ls -m (optional)" << endl;
}

int LSCommand::execute(std::string s) {
	set<string> names = filesys->getFileNames();
	if (s == "") {
		int counter = 0;
		for (set<string>::iterator it = names.begin(); it != names.end(); it++) {
			cout << *it;
			if (counter % 2 == 0) {
				for (int i = it->size(); i < space; i++) {
					cout << " ";
				}
			}
			else {
				cout << endl;
			}
			counter++;
		}
		if (counter % 2 != 0) {
			cout << endl;
		}
	}

	else {
		//-m
		if (s == "-m") {
			for (set<string>::iterator it = names.begin(); it != names.end(); it++) {
				cout << *it;
				for (int i = it->size(); i < space; i++) {
					cout << " ";
				}

				//MetadataDisplayVisitor* md = new MetadataDisplayVisitor();

				cout << endl;
			}
		}
		//command fails
		else {
			return error;
		}
	}


	return executed;
}