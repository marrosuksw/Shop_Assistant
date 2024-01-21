#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

struct ClientData {
	string name;
	string surname;
	string phoneNum;

	bool operator==(ClientData&);

	friend ostream& operator<<(ostream&, ClientData&);
	
};


class Client {
private:
	ClientData info;
public:
	Client(ClientData information) : info(information) {}

	bool operator==(Client&);

	ClientData getInfo();

	friend ostream& operator<<(ostream&, Client&);
};