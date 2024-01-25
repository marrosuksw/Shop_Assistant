#include"ClientDatabase.h"

using namespace std;

class ClientService {
private:
	ClientDatabase& database = database.getInstance();

	ClientData enterClientData();
	bool clientNameVerification(string&);
	bool clientDataVerification(string&, string&, string&);

	bool verifyClientExistence(ClientData);

	void cleanseIn();
public:
	void addClient();

};
