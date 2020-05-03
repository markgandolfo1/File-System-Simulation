#include "LSCommand.h"
#include "MetadataDisplayVisitor.h"

LSCommand::LSCommand(AbstractFileSystem* a) {
	filesys = a;
}

void LSCommand::displayInfo() {
	cout << "ls is responsible for outputting the names of the files in the file system and can be invoked using this command: ls [-m]" << endl;
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
			MetadataDisplayVisitor* md = new MetadataDisplayVisitor();
			for (set<string>::iterator it = names.begin(); it != names.end(); it++) {
				cout << *it;
				for (int i = it->size(); i < space; i++) {
					cout << " ";
				}
				AbstractFile* af = filesys->openFile(*it);
				filesys->closeFile(af);
				af->accept(md);
				cout << endl;
			}
			delete md;
		}
		//command fails
		else {
			return error;
		}
	}


	return executed;
}