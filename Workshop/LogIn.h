#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<algorithm>

using namespace std;

struct Pair {
	string login;
	string password;

	bool operator==(Pair&);
};

class LogIn {
public:
	string dbFilename = "assistantdb.txt";

	Pair enterLoginData();

	bool verifyLoginData();
};

