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
		return false;
	}
	else if (givenQuantity <= 0) {
		cout << endl << "Given input is wrong. The program will absolutely terminate now.";
		exit(0);
	}
	concrPart = concretePart;
	quant = givenQuantity;
	return true;
}
int Order::askForQuantity() {
	cout << "How many items would you like to buy? ";
	int itemQuantity;
	cin >> itemQuantity;
	return itemQuantity;
}

void Order::checkout() {
	int quantityToBuy = 0;
	PartData partData;
	ConcretePart concretePart(partData);
	ClientData clientData;
	Client client(clientData);
	client = getClient();
	if (validateQuantity(quantityToBuy, concretePart) == false) {
		cout << "it shoudlnt but it does";//add the client to the list of subscribers 
		//client.getInfo().phoneNum;
	}
	else {
		int totalPrice = partData.price * quantityToBuy;
		concretePart.getData().quantity -= quantityToBuy;
		db.changeInCollection(concretePart);
		db.overwriteCollection();
		db.print();
		invoice(totalPrice, quantityToBuy, concretePart, client);
		cout << "leaves invoice";
	}

	
}
void Order::invoice(int totalPrice, int quantity, ConcretePart concretePart, Client client) {
	//get data for the invoice?
	PartData partData = concretePart.getData();
	ClientData clientData = client.getInfo();
	string city, street, buildingNum, postalCode;
	string company = "Jimmy's Part Shop";
	string companyAdressStreet = "Jana Olbrachta 31";
	string companyAdressTown = "01-210 Warszawa";
	string ownerName = "Marcel Rosiak";
	string companyPhone = "505783763";
	time_t currentTime = time(nullptr);
	tm* localTime = localtime(&currentTime);
	char buffer[80];
	strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localTime);

	cout << "Fill in your adress:" << endl;
	cout << "City of residence: ";
	cin >> city;
	cout << endl << "Street: ";
	cin >> street;
	cout << endl << "Number of the building: ";
	cin >> buildingNum;
	cout << endl << "Postal code: ";
	cin >> postalCode;

	string invFilename = clientData.surname + "_invoice.txt";
	fstream invoiceFile(invFilename, ios::out);
	invoiceFile << "From:\t\t\tBill to:" << endl << company << "\t"
		<< clientData.name << " " << clientData.surname << endl
		<< companyAdressStreet << "\t" << street << " " << buildingNum << endl
		<< companyAdressTown << "\t\t" << city << " " << postalCode << endl
		<< companyPhone << "\t\t" << clientData.phoneNum << endl << endl
		<< "Date: " << buffer << endl << "\tItems:\t\tQuantity:  Price per item\tIn total:" << endl
		<< "1. " << partData.name << "\t" << quantity << "\t" << partData.price << "\t\t"
		<< partData.price*quantity;
	invoiceFile.close();
}