#include"Client.h"

Client::Client(int errorFlag) : info{ "", "", "-1" } {

}
void Client::update() {
	;
}
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
Client& Client::operator=(const Client& other) {
	if (this != &other) { 
		this->info = other.info; 
	}
	return *this;
}
Client::Client(ClientData information) : info(information) {}

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