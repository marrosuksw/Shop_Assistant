#include"ShoppingCart.h"


class Client : public IClient {
private:
	ClientData info;
	ShoppingCart userCart;
public:
	Client(int);
	Client(ClientData);

	ShoppingCart getCart();

	bool operator==(Client&);

	ClientData getInfo() override;

	void update() override;

	Client& operator=(const Client&);

	friend ostream& operator<<(ostream&, Client&);
};