#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

struct Pair {
	string log;
	string passwd;

	bool operator==(Pair&);
};

class LogIn {
public:

	Pair enterLoginData();

	bool verifyLoginData(string);
};

