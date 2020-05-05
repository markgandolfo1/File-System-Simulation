//responsible for defining CommandPrompt methods

#include "CommandPrompt.h"

CommandPrompt::CommandPrompt() {
	fso = 0;
	ffo = 0;
}

void CommandPrompt::setFileSystem(AbstractFileSystem* afs) {
	fso = afs;
}

void CommandPrompt::setFileFactory(AbstractFileFactory* aff) {
	ffo = aff;
}

int CommandPrompt::addCommand(std::string s, AbstractCommand* ac) {
	pair <map<string, AbstractCommand*>::iterator, bool> check;
	check = commands.insert(pair<string, AbstractCommand*>(s, ac));
	if (!check.second) {
		return alreadyexists;
	}
	return insertsuccess;
}

void CommandPrompt::listCommands() {
	for (map<string, AbstractCommand*>::iterator it = commands.begin(); it != commands.end(); it++) {
		cout << it->first << endl;
	}
}

//prompts user for input command
string CommandPrompt::prompt() {
	cout << "Enter a command, 'q' to quit, 'help' to see a list of commands, or 'help' preceding a the name of a command for a description of that command" << endl;
	cout << "$  ";
	string input;
	getline(cin, input);
	return input;
}

int CommandPrompt::run() {
	string space = " ";
	while (1) {
		string input = prompt();
		if (input == "q") {
			return quit;
		}
		if(input=="help"){
			listCommands();
		}
		else {
			size_t find = input.find(space);
			//one word
			if (find == string::npos) {
				map<string, AbstractCommand*>::iterator it = commands.find(input);
				if (it != commands.end()) {
					int result = (it->second)->execute("");
					if (result == error) {
						cout << "Command failed" << endl;
					}
				}
				else {
					cout << "Command does not exist" << endl;
				}
			}
			//more than one word
			else {
				istringstream com(input);
				string first;
				com >> first;
				string second;
				if (first == "help") {
					com >> second;
					map<string, AbstractCommand*>::iterator it = commands.find(second);
					if (it != commands.end()) {
						(it->second)->displayInfo();
					}
					else {
						cout << "Command does not exist" << endl;
					}
				}
				else {
					map<string, AbstractCommand*>::iterator it = commands.find(first);
					if (it != commands.end()) {
						string ans;
						if (com >> second) {
							ans = second;
						}
						while (com >> second) {
							ans = ans + " " + second;
						}
						int result = (it->second)->execute(ans);
						if (result == error) {
							cout << "Command failed" << endl;
						}
					}
					else {
						cout << "Command does not exist" << endl;
					}
				}
			}
		}
	}
}