#include"Client.h"


class ClientDatabase {
private:
	vector<Client> clientBase;
	string statFilename = "clientdb.txt";
public:
	void updateCollection();

	void addClientToBase(ClientData&);

	vector<Client> fetchClientCollection();

	void print();

};
