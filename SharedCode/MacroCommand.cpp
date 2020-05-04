#include "MacroCommand.h"

MacroCommand::MacroCommand(AbstractFileSystem* a) {
	filesys = a;
	aps = nullptr;
}

void MacroCommand::setParseStrategy(AbstractParsingStrategy* a) {
	aps = a;
}

void MacroCommand::addCommand(AbstractCommand* a) {
	cmds.push_back(a);
}

void MacroCommand::displayInfo() {
	cout << "MacroCommand is responsible for constructing commands out of other commands and can be invoked using +" << endl;
}

int MacroCommand::execute(std::string s) {
	vector<string> parsed = aps->parse(s);
	int i = 0;
	for (auto cmd : cmds) {
		int result = cmd->execute(parsed[i]);
		if (result != executed) {
			return result;
		}
		i++;
	}
	return executed;
}