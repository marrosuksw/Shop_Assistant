#include"ConcretePart.h"

ConcretePart::ConcretePart(PartData partDat)
	: pData(partDat){}

void ConcretePart::setQuantity(int q) {
	pData.quantity = q;
}
int ConcretePart::getQuantity() {
	return pData.quantity;
}
PartData ConcretePart::getData() {
	return pData;
}