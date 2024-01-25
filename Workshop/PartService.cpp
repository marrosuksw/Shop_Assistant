#include"PartService.h"

void PartService::displayParts() {
	partsDatabase.print();
}
ConcretePart PartService::addQuantity() {
	cout << "Choose a part's ID to restock that part: " << endl;
	partsDatabase.print();
	int partID;
	do{
	cin >> partID;
	} while (!partsDatabase.checkIfPartExists(partID));
	ConcretePart concretePart = partsDatabase.getConcPartThroughID(partID);
	cout << "Choose how much do you want to restock: " << endl;
	int newQuantity = 0;
	do {
		cin >> newQuantity;
	} while (newQuantity < 1);

	concretePart.getData().quantity += newQuantity;
	partsDatabase.changeInCollection(concretePart);
	partsDatabase.overwriteCollection();
	partsDatabase.print();
	return concretePart;
}