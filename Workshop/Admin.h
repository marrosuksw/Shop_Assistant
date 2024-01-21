#include<iostream>
#include<string>

using namespace std;

class Admin {
private:
	string login;
	string password;
public:
	Admin();

	bool isInDatabase();

	void setLogin(string log);

	
};

//assistant inserts login data and the password -> a method compares it to the data from the Admin database
// ->returns a true/false. Then a method "verify()" uses that compare method and its output to authenticate
// the data.