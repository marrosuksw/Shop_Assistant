#include"Client.h"


class ClientDatabase {
private:
	vector<Client> clientBase;
	string statFilename = "clientdb.txt";
	//vector<Client>::iterator it;
public:
	void updateCollection();

	void addClientToBase(ClientData&);

	vector<Client> fetchClientCollection();

	void print();

};
