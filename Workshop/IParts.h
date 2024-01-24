#include"IClient.h"

class IParts {
public:
	/*virtual ~IParts();*/
	/*virtual void attach(IClient* client) = 0;
	virtual void detach(IClient* client) = 0;
	virtual void notify() = 0;*/
};

struct PartData {
	string carBrand;
	string name;
	string manufacturer;
	int price;
	int quantity;
	int partID;
	bool operator==(const PartData& elem);
};



