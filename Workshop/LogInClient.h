#include"ClientDatabase.h"

using namespace std;

class LogInClient {

public:
	ClientData enterClientData();

	bool verifyClientExistance();

	void addClient(ClientData&);
};
