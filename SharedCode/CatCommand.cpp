#include "CatCommand.h"
#include <sstream>
#include <vector>

CatCommand::CatCommand(AbstractFileSystem* a) {
	filesys = a;
}

void CatCommand::displayInfo() {
	cout << "cat is responsible for appending to a file and can be invoked using this command: cat <filename> [-a]" << endl;
}

int CatCommand::execute(std::string s) {
	string space = " ";
	size_t find = s.find(space);
	if (s == "") {
		return error;
	}
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
			AbstractFile* af = filesys->openFile(s);
			if (af == 0) {
				return couldnotopen;
			}
			vector<char> towrite;
			for (int i = 0; i < output.size(); i++) {
				towrite.push_back(output[i]);
			}
			af->write(towrite);
			filesys->closeFile(af);
		}
	}

	else {
		istringstream com(s);
		string first;
		com >> first;
		string second;
		com >> second;
		if (second == "-a") {
			AbstractFile* af = filesys->openFile(first);
			if (af == 0) {
				return couldnotopen;
			}
			vector<char> read = af->read();
			for (char c : read) {
				cout << c;
			}
			cout << endl;
			filesys->closeFile(af);

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
				AbstractFile* af = filesys->openFile(first);
				if (af == 0) {
					return couldnotopen;
				}
				vector<char> toappend;
				for (int i = 0; i < output.size(); i++) {
					toappend.push_back(output[i]);
				}
				int ret = af->append(toappend);
				filesys->closeFile(af);
				if (ret != 0) {
					return ret;
				}
			}
		}
		else {
			return commandDNE;
		}
	}
	return success;
}