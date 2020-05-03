#pragma once
using namespace std;
#include <string>

enum exkeys {executed, error, couldnotopen, commandDNE};

class AbstractCommand {
public:
	virtual int execute(std::string) = 0;
	virtual void displayInfo() = 0;
	virtual ~AbstractCommand() = default;
};