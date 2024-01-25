#include"ConcretePart.h"

ConcretePart& ConcretePart::operator=(const ConcretePart& other) {
	if (this != &other) {
		this->pData = other.pData;
	}
	return *this;
}

ConcretePart::ConcretePart(PartData partDat)
	: pData(partDat){}

void ConcretePart::setQuantity(int q) {
	pData.quantity = q;
}
int ConcretePart::getQuantity() {
	return pData.quantity;
}
PartData& ConcretePart::getData() {
	return pData;
}
int ConcretePart::getID() {
	return pData.partID;
}
bool PartData::operator==(const PartData& elem) {
	return partID == elem.partID;
}
bool ConcretePart::operator==(ConcretePart& elem) {
		return this->getID() == elem.getID();
}

string ConcretePart::getName() {
	return pData.name;
}
string ConcretePart::getManufacturer() {
	return pData.manufacturer;
}
string ConcretePart::getCarBrand() {
	return pData.carBrand;
}
int ConcretePart::getPrice() {
	return pData.price;
}
void ConcretePart::addObserver(IClient* observer) {
	observers.push_back(observer);
}

void ConcretePart::removeObserver(IClient* observer) {
	auto it = std::find(observers.begin(), observers.end(), observer);
	if (it != observers.end()) {
		observers.erase(it);
	}
}

void ConcretePart::notifyObservers() {
	cout << "Notifications of availability were sent to the clients.";
	cout << observers.size();
	for (auto it = observers.begin(); it != observers.end(); it++) {
		IClient* client = *it;
		cout << "should be name";
		cout << client->getInfo().name;
		client->update();
	}
}
vector<IClient*> ConcretePart::getObserverList() {
	return observers;
}
void ConcretePart::addObserverAndUpdateFile(IClient* observer, int quantity, ConcretePart& conc) {
	addObserver(observer);
	string filename = to_string(conc.getID()) + "_observers.txt";
	ofstream observerFile;
	observerFile.open(filename, ios::app);
	if(observerFile.is_open()) {
		observerFile << observer->getInfo().phoneNum << " " << quantity << "\n";
		observerFile.close();
	}
	else {
		cerr << "Unable to open observers file.\n";
	}
}
