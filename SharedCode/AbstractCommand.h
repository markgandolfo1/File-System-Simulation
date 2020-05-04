//parent class for every command. All commands inherit this. 
#pragma once
using namespace std;
#include <string>
//this includes enums to be outputted as values for the commands/ 
enum exkeys {executed, error, couldnotopen, commandDNE};

class AbstractCommand {
public:
	//execute preforms command
	virtual int execute(std::string) = 0;
	//display is like a usage function.
	virtual void displayInfo() = 0;
	virtual ~AbstractCommand() = default;
};