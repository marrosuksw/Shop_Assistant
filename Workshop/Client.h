#include"PartService.h"


class Client : public IClient {
private:
	ClientData info;
public:
	Client(int);
	Client(ClientData);

	bool operator==(Client&);

	ClientData getInfo() override;

	void update() override;

	Client& operator=(const Client&);

	friend ostream& operator<<(ostream&, Client&);
};