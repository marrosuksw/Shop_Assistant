#include"Client.h"

bool ClientData::operator==(ClientData& elem) {
	if (name == elem.name && surname == elem.surname && phoneNum == elem.phoneNum) {
		return true;
	}
	return false;
}
bool Client::operator==(Client& elem) {
	if (info == elem.info) {
		return true;
	}
	return false;
}

ClientData Client::getInfo() {
	return info;
}

ostream& operator<<(ostream& os, ClientData& data) {
	os << data.name << ' ' << data.surname << ' ' << data.phoneNum;
	return os;
}

ostream& operator<<(ostream& os, Client& cl) {
	os << cl.info;
	return os;
}