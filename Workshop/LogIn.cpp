#include"LogIn.h"

Pair LogIn::enterLoginData() {
	Pair data;
	cout << "login: ";
	cin >> data.log;
	cout << "password: ";
	cin >> data.passwd;
	cout << endl;
	return data;
}
//make it a template function?
//make both of this and LogInClient children of a InterfaceLogin class (virtual class)

bool LogIn::verifyLoginData(string filename) {

	Pair adminLoginAttempt = enterLoginData();

	ifstream file;
	file.open(filename);
	string correctLogin, correctPassword;
	getline(file, correctLogin);
	getline(file, correctPassword);
	//cout << correctLogin << "  " << correctPassword;
	Pair fileData;
	fileData.log = correctLogin;
	fileData.passwd = correctPassword;
	if (adminLoginAttempt == fileData) {
		file.close();
		return true;
	}
	file.close();
	return false;
}

bool Pair::operator==(Pair& elem)
	{
	if (log == elem.log && passwd == elem.passwd) return true;
	else return false;
	}
