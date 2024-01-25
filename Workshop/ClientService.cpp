#include"ClientService.h"


ClientData ClientService::enterClientData() {
	ClientData temp;
	do {
		cout << endl << "Enter the client's name: ";
		cin >> temp.name;
		cleanseIn();
		cout << endl << "Enter the client's surname: ";
		cin >> temp.surname;
		cleanseIn();
		cout << endl << "Enter the client's phone number: ";
		cin >> temp.phoneNum;
		cleanseIn();
	} while (clientDataVerification(temp.name, temp.surname, temp.phoneNum) == false);
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

bool ClientService::clientDataVerification(string& clientName, string&clientSurname, string& pNumber) {

	clientNameVerification(clientName);
	clientNameVerification(clientSurname);
	if (pNumber.size() != 9) {
		cout << "Please enter valid data" << endl;
		return false;
	}
	for (char c : pNumber)
		if (isalpha(c)) {
			cout << "Please enter valid data." << endl;
			return false;
		}
	return true;
}
bool ClientService::clientNameVerification(string& clientName) {
	if (isupper(clientName[0])) {
		return false;
	}
	for (char c : clientName) {
		if (isdigit(c)) {;
			return false;
		}
	}
	for (auto it = clientName.begin() + 1; it != clientName.end(); ++it) {
		if (isupper(*it)) {
			return false;
		}
	}
}

void ClientService::cleanseIn() {
	if (cin.fail())
		cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}