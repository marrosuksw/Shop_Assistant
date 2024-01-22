#include"IParts.h"
#include<list>

class ConcretePart : public IParts {
private:
	PartData pData;
	list<IClient*> observersList;
	
public:
	ConcretePart(PartData);

	string getBrand();
	string getName();
	int getPrice();
	int getQuantity();
	//void attach(IClient*) override;
	//void detach(IClient*) override;
	//void notify() override;
	void setQuantity(int);
	PartData getData();
};
