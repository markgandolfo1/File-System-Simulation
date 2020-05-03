#include "CopyCommand.h"
#include "MetadataDisplayVisitor.h"

CopyCommand::CopyCommand(AbstractFileSystem* a) {
	filesys = a;
}

void CopyCommand::displayInfo() {
	cout << "cp is responsible for copying a file to a new file with a new name:cp <file_to_copy> <new_name_with_no_extension>" << endl;
}

int CopyCommand::execute(std::string s) {
	return 0;
}