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
	logtest2.verifyClientExistence();
	PartsDatabase pd;
	pd.updateCollection();
	pd.print();
	return 0;
}