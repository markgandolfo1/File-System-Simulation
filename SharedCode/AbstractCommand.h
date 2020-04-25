using namespace std;
#include <string>

enum exkeys {executed, error};

class AbstractCommand {
public:
	virtual int execute(std::string);
	virtual void displayInfo();
	virtual ~AbstractCommand() = default;
};