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

void LogInClient::addClient(ClientData& newClientData) {

	ClientDatabase db;
	db.addClientToBase(newClientData);
}

bool LogInClient::verifyClientExistance() {

	ClientData clientGivenData = enterClientData();
	ClientDatabase database;

	database.updateCollection();

	vector<Client> clientCollection = database.fetchClientCollection();
	vector<Client>::iterator it;

	for (it = clientCollection.begin(); it != clientCollection.end(); it++) {
		Client tempObj = *it;
		if (tempObj.getInfo() == clientGivenData) {
			cout << "Client exists";
			return true;
		}
	}
	cout << "Client doesnt exist. He/She will be added to the list of clients.";
	addClient(clientGivenData);
	return true;
}
	//ClientDatabase dat;
	//vector<Client> tempColl = dat.fetchClientCollection();
	//vector<Client>::iterator *it = nullptr;
	//for(*it = tempColl.begin(); *it != tempColl.end(), it++){
	//	if()
	//ifstream clientFile;
	//string tName, tSurn, tPhone;
	//clientFile.open(filename);
	//while (clientFile.eof() != true) {
	//	getline(clientFile, tName, ' ');
	//	getline(clientFile, tSurn, ' ');
	//	getline(clientFile, tPhone);
	//	ClientData temp;
	//	temp.name = tName;
	//	temp.surname = tSurn;
	//	temp.phoneNum = tPhone;
	//	//save elements to vector, iterate through elements with an iterator?
	//	if (clientGivenData == temp) {
	//		cout << "yeah we got him";
	//		clientFile.close();
	//		return true;
	//	}
	//}
	//cout << "nah he aint";
	//clientFile.close();
	//return false;

