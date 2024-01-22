#include"LogIn.h"

using namespace std;

struct ClientData {
	string name;
	string surname;
	string phoneNum;

	bool operator==(ClientData&);

	friend ostream& operator<<(ostream&, ClientData&);

};

class IClient {
	public:

		virtual ClientData getInfo() = 0;

		virtual void update() = 0;

};