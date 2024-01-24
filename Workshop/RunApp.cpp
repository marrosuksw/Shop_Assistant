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
		partService.addQuantity();
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