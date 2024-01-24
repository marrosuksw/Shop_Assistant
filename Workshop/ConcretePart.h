#include"IParts.h"
#include<list>

class ConcretePart : public IParts {
private:
	PartData pData;
	list<IClient*> observersList;
	
public:
	ConcretePart(PartData);
	ConcretePart& operator=(const ConcretePart&);
	int getQuantity();
	string getName();
	string getManufacturer();
	string getCarBrand();
	int getPrice();
	//void attach(IClient*) override;
	//void detach(IClient*) override;
	//void notify() override;
	void setQuantity(int);
	PartData& getData();
	int getID();
	bool operator==(ConcretePart&);
};
