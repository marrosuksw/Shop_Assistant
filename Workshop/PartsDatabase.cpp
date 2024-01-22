#include"PartsDatabase.h"

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
		partsBase.push_back(tempPart);
	}
}

vector<ConcretePart> PartsDatabase::fetchPartsCollection() {
	return partsBase;
}

void PartsDatabase::print() {
	vector<ConcretePart> bruh = fetchPartsCollection();
		for (it = bruh.begin(); it != bruh.end(); it++) {
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