#include"ClientService.h"


class Order {
private:
	PartsDatabase& db = db.getInstance();
	ClientDatabase& clDatabase = clDatabase.getInstance();
	void cleanseIn();
	int choosePart();
	int askForQuantity();
	bool validateQuantity(int&, ConcretePart&);
	void invoice(int, int, ConcretePart, Client);
	Client getClient();
	void addClientNumberToObserverList(Client);
	void readObserversFromFile(const string&);
public:
	string getFilename();
	void checkout();

};