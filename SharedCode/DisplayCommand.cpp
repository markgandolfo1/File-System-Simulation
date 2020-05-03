#include "DisplayCommand.h"

DisplayCommand::DisplayCommand(AbstractFileSystem* a) {
	filesys = a;
	
}

void DisplayCommand::displayInfo() {
	cout << "display is responsible for creating a file and can be invoked using this command: touch <filename>" << endl;
}

int DisplayCommand::execute(std::string s) {
	size_t find = s.find(" ");
	//one word
	if (find == string::npos) {
		AbstractFile* f = filesys->openFile(s);
		
		BasicDisplayVisitor* d = new BasicDisplayVisitor();
		f->accept(d);
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
				for (int i = 0; i < v.size(); ++i) {
					cout << v[i];
				}
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