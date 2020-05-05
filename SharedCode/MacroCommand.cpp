//responsible for defining MacroCommand methods

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
	//gets parsed commands
	vector<string> parsed = aps->parse(s);
	int i = 0;
	//iterates through the commands and executes on the parsed strings
	for (auto cmd : cmds) {
		int result = cmd->execute(parsed[i]);
		if (result != executed) {
			return result;
		}
		i++;
	}
	return executed;
}