#include"LogIn.h"

Pair LogIn::enterLoginData() {
	Pair data;
	cout << "login: ";
	cin >> data.login;
	cout << "password: ";
	cin >> data.password;
	cout << endl;
	return data;
}

bool LogIn::verifyLoginData() {



	ifstream file;
	file.open(dbFilename);
	string correctLogin, correctPassword;
	getline(file, correctLogin);
	getline(file, correctPassword);
	Pair fileData;
	fileData.login = correctLogin;
	fileData.password = correctPassword;
	int failedAttempt = 0;
	while (failedAttempt < 3) {
		Pair adminLoginAttempt = enterLoginData();
		if (adminLoginAttempt == fileData) {
			file.close();
			return true;
		}
		failedAttempt++;
		cout << "Login attempt failed, please try again. You have " << 3 - failedAttempt << " attempt(s) left";
		cout << endl;
	}
	file.close();
	return false;
}

bool Pair::operator==(Pair& elem)
	{
	if (login == elem.login && password == elem.password) return true;
	else return false;
	}
