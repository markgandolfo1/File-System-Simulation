#include "CatCommand.h"
#include <sstream>

CatCommand::CatCommand(AbstractFileSystem* a) {
	filesys = a;
}

void CatCommand::displayInfo() {
	cout << "cat is responsible for appending to a file and can be invoked using this command: cat <filename> [-a]" << endl;
}

int CatCommand::execute(std::string s) {
	string space = " ";
	size_t find = s.find(space);
	//one word:
	if (find == string::npos) {
		string input = "";
		string output = "";
		for (int i = 0; input != ":wq" && input != ":q"; i++) {
			getline(cin, input);
			if (input != ":wq" && input != ":q") {
				if (i != 0) {
					output = output + "\n";
				}
				output = output + input;
			}
		}

		if (input == ":wq") {

		}
	}

	else {
		istringstream com(s);
		string first;
		com >> first;
		string second;
		com >> second;
		if (second == "-a") {
			cout << "yessirski";
		}

		else {

		}
	}
	return 0;
}