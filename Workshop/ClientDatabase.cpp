#include"ClientDatabase.h"

ClientDatabase::ClientDatabase(){}
ClientDatabase::~ClientDatabase() {
}

void ClientDatabase::addClientToBase(ClientData& clData) {
	Client tempCl(clData);
	ofstream clFile;
	clFile.open(statFilename, ios::app);
	if (!clFile) {
		cout << "File opening error, please contact our support at 1-800-2063-2433";
	}
	clFile << endl << tempCl;
	updateCollection();
}
void ClientDatabase::updateCollection() {
	ifstream clFile;
	clFile.open("clientdb.txt");
	while (!clFile.eof()) {
		string cName, cSur, cPhone;
		getline(clFile, cName, ' ');
		getline(clFile, cSur, ' ');
		getline(clFile, cPhone);
		ClientData data;
		//overload the "=" operator for ClientData to shorten the code
		data.name = cName;
		data.surname = cSur;
		data.phoneNum = cPhone;
		Client tempCl(data);
		clientBase.push_back(tempCl);
	}
}
vector<Client> ClientDatabase::fetchClientCollection() {
	updateCollection();
	return clientBase;
}
Client ClientDatabase::getClientThroughNumber(string phoneNum) {
	updateCollection();
	ClientData dat;
	Client concCl(dat);
	for (it = clientBase.begin(); it != clientBase.end(); it++) {
		concCl = *it;
		if (concCl.getInfo().phoneNum == phoneNum) {
			return concCl;
		}
	}
	cerr << "no such client.";
	return Client(-1);
}