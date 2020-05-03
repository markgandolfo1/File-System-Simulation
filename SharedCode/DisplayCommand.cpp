#include "DisplayCommand.h"

DisplayCommand::DisplayCommand(AbstractFileSystem* a) {
	filesys = a;
	
}

void DisplayCommand::displayInfo() {
	cout << "display is responsible for opening a file and displaying its contents - it can be invoked using this command: ds <filename> [-d]" << endl;
}

int DisplayCommand::execute(std::string s) {
	size_t find = s.find(" ");
	//one word
	if (find == string::npos) {
		AbstractFile* f = filesys->openFile(s);
		if (f != 0) {
			BasicDisplayVisitor* d = new BasicDisplayVisitor();
			f->accept(d);
			filesys->closeFile(f);
			delete d;
		//	cout << endl;
			return success;
		}
		else {
			return couldnotcreate;
		}
	

	}
	else {
		istringstream ss(s);
		string first;
		ss >> first;
		string second;
		ss >> second;
		if (second == "-d") {
			AbstractFile* f = filesys->openFile(first);
			if (f != 0) {
				vector<char> v = f->read();
				for (char c : v) {
					cout << c;
				}
				cout << endl;
				filesys->closeFile(f);
				return success;
			}
			else {
				return couldnotcreate;
			}
		}
		else {
			return couldnotcreate;
		}
	}
}