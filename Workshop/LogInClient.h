#include"ClientDatabase.h"

using namespace std;

class LogInClient {
private:
	ClientDatabase& database = database.getInstance();
public:
	ClientData enterClientData();

	bool verifyClientExistence();
};
