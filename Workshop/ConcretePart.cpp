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