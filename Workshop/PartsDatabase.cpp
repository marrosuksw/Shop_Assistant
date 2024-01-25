#include"PartsDatabase.h"

PartsDatabase::PartsDatabase(){}
PartsDatabase::~PartsDatabase(){}

void PartsDatabase::overwriteCollection() {
	ofstream ptFile(statFilename, ios::trunc);
	for (auto c : partsBase) {
		ptFile << c.getCarBrand() << "\t" << c.getName() << "\t" << c.getManufacturer() << "\t" << c.getPrice()
			<< "\t" << c.getQuantity() << "\t" << c.getID() << endl;
	}
}

void PartsDatabase::updateCollection() {
	ifstream ptFile;
	ptFile.open(statFilename);
	if (!ptFile.is_open()) cerr << "file not working.";
	string brand, name, manufact;
	int prc;
	int quantity;
	int ID;
	while (ptFile >> brand >> name >> manufact >> prc >> quantity >> ID) {
		PartData pdata;
		pdata.carBrand = brand;
		pdata.manufacturer = manufact;
		pdata.name = name;
		pdata.price = prc;
		pdata.quantity = quantity;
		pdata.partID = ID;
		ConcretePart tempPart(pdata);

		bool found = false;
		for (auto& part : partsBase) {
			if (part == tempPart) {
				found = true;
				break;
			}
		}
		if (!found) {
			partsBase.push_back(tempPart);
		}
	}
}

vector<ConcretePart> PartsDatabase::fetchPartsCollection() {
	return partsBase;
}

void PartsDatabase::print() {
	updateCollection();
	cout << "Brand:\t\tItem:\t     Made by: Price: Quantity: ID:" << endl;
		for (it = partsBase.begin(); it != partsBase.end(); it++) {
			ConcretePart some = *it;
			PartData dat = some.getData();
			cout << dat.carBrand << "\t";
			cout << dat.name << "\t";
			cout << dat.manufacturer << "\t";
			cout << dat.price << "\t";
			cout << dat.quantity << "\t";
			cout << dat.partID << endl;
		}
}
bool PartsDatabase::checkIfPartExists(int partID) {
	vector<ConcretePart> tempV = fetchPartsCollection();
	PartData partData;
	ConcretePart tempObj(partData);
	for (it = tempV.begin(); it != tempV.end(); it++) {
		tempObj = *it;
		if (tempObj.getID() == partID) {
			return true;
		}
	}
	return false;
}
ConcretePart PartsDatabase::getConcPartThroughID(int partID){
	vector<ConcretePart> tempV = fetchPartsCollection();
	PartData partData;
	ConcretePart tempObj(partData);
	for (it = tempV.begin(); it != tempV.end(); it++) {
		tempObj = *it;
		if (tempObj.getID() == partID) {
			return tempObj;
		}
	}
	exit(0);
}
void PartsDatabase::changeInCollection(ConcretePart concretePart) {
	for (auto& part : partsBase) {
		if (part == concretePart) {
			part = concretePart;
			return;
		}
	}

}
