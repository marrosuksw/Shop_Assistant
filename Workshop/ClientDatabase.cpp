#include"ClientDatabase.h"

void ClientDatabase::addClientToBase(ClientData& clData) {
	Client tempCl(clData);
	ofstream clFile;
	clFile.open(statFilename, ios::app);
	if (!clFile) {
		cout << "File opening error, please contact our support at 1-800-2063-2433";
	}
	clFile << endl << tempCl;
	cout << "Client added";
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
	return clientBase;
}
//void ClientDatabase::print() {
//	vector<Client> bruh = fetchClientCollection();
//	for (it = bruh.begin(); it != bruh.end(); it++) {
//		Client some = *it;
//		ClientData dat = some.getInfo();
//		cout << dat.name << endl;
//		cout << dat.surname << endl;
//		cout << dat.phoneNum << endl;
//	}
//}