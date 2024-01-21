#include"LogIn.h"
#include"LogInClient.h"


int main() {
	LogIn logtest;
	string filename = "assistantdb.txt";
	if (logtest.verifyLoginData(filename) == true) cout << "yay";
	else {
		cout << "nay";
		return 0;
	}
	LogInClient logtest2;
	if (logtest2.verifyClientExistance() == true) cout << endl << "damn it worked";
	return 0;
}