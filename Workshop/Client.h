#include"PartsDatabase.h"


class Client : public IClient {
private:
	ClientData info;
public:
	Client(ClientData);

	bool operator==(Client&);

	ClientData getInfo() override;

	void update() override;



	friend ostream& operator<<(ostream&, Client&);
};