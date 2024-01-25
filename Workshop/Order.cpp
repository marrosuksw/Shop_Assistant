#include"Order.h"
#pragma warning(disable : 4996)

Client Order::getClient() {
	ClientData clientData;
	Client client(clientData);
	do {
		cout << "Confirm the client's phone number: ";
		string number;
		cin >> number;
		client = clDatabase.getClientThroughNumber(number);
	} while (client.getInfo().phoneNum == "-1");
	return client;
}

int Order::choosePart() {
	cout << "Type in the ID of your wanted part: ";
	int itemID;
	cin >> itemID;
	if (db.checkIfPartExists(itemID)) {
		return itemID;
	}
	cout << "Such part does not exist in this shop.";
	return -1;
}
bool Order::validateQuantity(int& quant, ConcretePart& concrPart) {
	int itemID = choosePart();
	PartData partData;
	ConcretePart concretePart(partData);
	concretePart = db.getConcPartThroughID(itemID);
	int quantity = concretePart.getQuantity();
	int givenQuantity = askForQuantity();
	if (quantity < givenQuantity) {
		concrPart = concretePart;
		quant = givenQuantity;
		return false;
	}
	else if (givenQuantity <= 0) {
		cout << endl << "Given input is wrong. The program will absolutely terminate now.";
		exit(0);
	}
	quant = givenQuantity;
	concrPart = concretePart;
	return true;
}
int Order::askForQuantity() {
	cout << "How many items would you like to buy? ";
	int itemQuantity;
	cin >> itemQuantity;
	return itemQuantity;
}

void Order::checkout() {
	int quantityToBuy=0;
	PartData partData;
	ConcretePart concretePart(partData);
	ClientData clientData;
	Client client(clientData);
	client = getClient();
	if (validateQuantity(quantityToBuy, concretePart) == false) {
		concretePart.addObserverAndUpdateFile(&client, quantityToBuy, concretePart);
		cout << "The client has been added to the list of observers." << endl;
		cout << " If the item is in stock, the client will be notified through SMS.";
	}
	else {
		int totalPrice = partData.price * quantityToBuy;
		concretePart.getData().quantity -= quantityToBuy;
		db.changeInCollection(concretePart);
		db.overwriteCollection();
		db.print();
		invoice(totalPrice, quantityToBuy, concretePart, client);
	}

	
}
void Order::invoice(int totalPrice, int quantity, ConcretePart concretePart, Client client) {
	//get data for the invoice?
	PartData partData = concretePart.getData();
	ClientData clientData = client.getInfo();
	string city, cityLong = "", street, streetLong="", buildingNum, postalCode;
	string company = "Jimmy's Part Shop";
	string companyAdressStreet = "Jana Olbrachta 31";
	string companyAdressTown = "01-210 Warszawa";
	string ownerName = "Marcel Rosiak";
	string companyPhone = "505783763";
	time_t currentTime = time(nullptr);
	tm* localTime = localtime(&currentTime);
	char buffer[80];
	strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localTime);

	cout << endl << "Fill in your adress : " << endl;
	cout << "(Keep in mind - you can only enter a two-section city name." << endl;
	cout << "Anything afterwards will be: client's street name, building number and postal code)" << endl << endl;
	cout << "City of residence: ";
	cin >> city;
	if (getchar() == ' ') {
		cin >> cityLong;
		cleanseIn();
	}
	if (getchar() == ' ') {
		cout << "Please don't press spaces after giving data." << endl;
		cleanseIn();
	}
	cout <<"Street: (maximum - two-section street name)";
	cin >> street;	
	if (getchar() == ' '){
		cin>>streetLong;
		cleanseIn();
	}
	cout <<"Number of the building: ";
	cin >> buildingNum;
	cleanseIn();
	cout <<"Postal code: ";
	cin >> postalCode;
	cleanseIn();

	string invFilename = clientData.surname + "_" + clientData.phoneNum + "_invoice.txt";
	fstream invoiceFile(invFilename, ios::out);
	invoiceFile << "From:\t\t\tBill to:" << endl << company << "\t"
		<< clientData.name << " " << clientData.surname << endl
		<< companyAdressStreet << "\t" << street << " " << streetLong << " " << buildingNum << endl
		<< companyAdressTown << "\t\t" << postalCode << city << " " << cityLong << " " << endl
		<< companyPhone << "\t\t" << clientData.phoneNum << endl << endl
		<< "Date: " << buffer << endl << "Items:\t   Quantity:  Price per item\tIn total:" << endl
		<< "1. " << partData.name << "\t" << quantity << "\t" << partData.price << "\t\t"
		<< partData.price*quantity;
	invoiceFile.close();
}
void Order::cleanseIn() {
	if (cin.fail())
		cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}