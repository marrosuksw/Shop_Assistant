#include"ClientService.h"


ClientData ClientService::enterClientData() {
	ClientData temp;
	cout << "Enter the client's name: ";
	cin >> temp.name;
	cout << endl << "Enter the client's surname: ";
	cin >> temp.surname;
	cout << endl << "Enter the client's phone number: ";
	cin >> temp.phoneNum;
	cout << endl;
	return temp;
}

bool ClientService::verifyClientExistence(ClientData clientData) {

	vector<Client> clientCollection = database.fetchClientCollection();
	vector<Client>::iterator it;

	for (it = clientCollection.begin(); it != clientCollection.end(); it++) {
		Client client = *it;
		if (client.getInfo() == clientData) {
			cout << "Client exists." << endl;
			return true;
		}
	}
	cout << "Client doesnt exist. He/She will be added to the list of clients." << endl;
	return false;
}
void ClientService::addClient() {
	ClientData clientData = enterClientData();
	if (!verifyClientExistence(clientData)) {
		database.addClientToBase(clientData);
	}
}