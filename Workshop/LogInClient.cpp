#include"LogInClient.h"


ClientData LogInClient::enterClientData() {
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

bool LogInClient::verifyClientExistence() {

	ClientData clientGivenData = enterClientData();
	ClientDatabase database;

	database.updateCollection();

	vector<Client> clientCollection = database.fetchClientCollection();
	vector<Client>::iterator it;

	for (it = clientCollection.begin(); it != clientCollection.end(); it++) {
		Client tempObj = *it;
		if (tempObj.getInfo() == clientGivenData) {
			cout << "Client exists" << endl;
			return true;
		}
	}
	cout << "Client doesnt exist. He/She will be added to the list of clients.";
	database.addClientToBase(clientGivenData);
	return true;
}
