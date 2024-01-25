#include"RunApp.h"

int RunApp::RunTheApplication() {
	LogIn login;
	if (login.verifyLoginData() == false){
		cout << "Login failed. The program will terminate.";
		return 0;
	}
	//three options crossroads
	//alt1
	startCommunicate();
	int numChoice;
	cin >> numChoice;
	if (numChoice == 1 || numChoice == 2) {
		if (numChoice == 1) {
			ClientService clientService;
			clientService.addClient();
			PartService partService;
			partService.displayParts();
		}
		else {
			PartService partService;
			partService.displayParts();
			ClientService clientService;
			clientService.addClient();
		}
		Order order;
		order.checkout();
	}
	else if (numChoice == 3) {
		PartService partService;
		ConcretePart concretePart = partService.addQuantity();
		vector<string> clientsNumbers;
		int quantity;
		getNumbersToContainer(clientsNumbers, quantity, concretePart);
		if (clientsNumbers.size() != 0 && concretePart.getData().quantity >= quantity) {
			//ClientData clData;
			//Client client(clData);
			//ClientDatabase& clDatabase = clDatabase.getInstance();
			//for (auto it = clientsNumbers.begin(); it != clientsNumbers.end(); it++) {
			//	client = clDatabase.getClientThroughNumber(*it);
			//	concretePart.getObserverList().push_back(&client);
			//}
			concretePart.notifyObservers();
			string filename = to_string(concretePart.getID()) + "_observers.txt";
			ofstream file(filename, ios::trunc);
			file.close();
		}
		else cout << "Nobody is awaiting this addition." << endl;
		


	}
	else {
		cout << "Wrong data has been given. The program will terminate now.";
		exit(-1);
	}

}
void RunApp::startCommunicate() {
	cout << "\t\t+----------------------------------+" << endl;
	cout << "\t\t|Jimmy's Part Shop Assistant Helper|" << endl;
	cout << "\t\t+----------------------------------+" << endl;
	cout << "\t\tver. 1.0.2, author: Marcel Rosiak" << endl << endl << endl;
	cout << "Choose one of the following options by typing in the number:" << endl;
	cout << "1 - Verify or add a client." << endl;
	cout << "2 - Show the complete list of parts and make an order." << endl;
	cout << "3 - Add a part to stock." << endl;
}
void RunApp::getNumbersToContainer(vector<string>& phoneNumbers, int& quantity, ConcretePart& concretePart) {
	string filename = to_string(concretePart.getID()) + "_observers.txt";
		ifstream file(filename);
		if (file.is_open()) {
			string phoneNumber;
			while (file >> phoneNumber >> quantity) {
				// Dodaj numer telefonu do kontenera
				phoneNumbers.push_back(phoneNumber);
			}
			file.close();
		}
		else {
			cerr << "Unable to open file: " << "_observers.txt" << endl;
		}
}