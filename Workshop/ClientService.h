#include"ClientDatabase.h"

using namespace std;

class ClientService {
private:
	ClientDatabase& database = database.getInstance();

	ClientData enterClientData();

	bool verifyClientExistence(ClientData);
public:
	void addClient();
};
