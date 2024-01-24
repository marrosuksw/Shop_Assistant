#include"ClientService.h"


class Order {
private:
	PartsDatabase& db = db.getInstance();
	ClientDatabase& clDatabase = clDatabase.getInstance();
public:
	int choosePart();
	int askForQuantity();
	bool validateQuantity(int&, ConcretePart&);
	void invoice(int, int, ConcretePart, Client);
	void checkout();
	Client getClient();
};