//responsible for defining CopyCommand methods

#include "CopyCommand.h"


CopyCommand::CopyCommand(AbstractFileSystem* a) {
	filesys = a;
	
}

void CopyCommand::displayInfo() {
	cout << "cp is responsible for copying a file to a new file with a new name:cp <file_to_copy> <new_name_with_no_extension>" << endl;
}

int CopyCommand::execute(std::string s) {
	size_t find = s.find(" ");
	//one word
	if (s == "") {
		return error;
	}
	if (find == string::npos) {
		return couldnotcreate;
	}
	else {
		istringstream ss(s);
		string first;
		ss >> first;
		string second;
		ss >> second;
		AbstractFile* f = filesys->openFile(first);	
		//file can't be opened:
		if (f == 0) {
			return error;
		}
		size_t pt = first.find(".");
		string ext = first.substr(pt, pt + 3);
		if (f != 0) {
			AbstractFile* copy = f->clone(second + ext);
			filesys->closeFile(f);
			if (filesys->addFile(second + ext, copy) == success) {
				return success;
			}
			
				
			}
			
		}
	return couldnotcreate;

	}
