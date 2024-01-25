#include"PartData.h"
#include<list>

class ConcretePart {
private:
	PartData pData;
	vector<IClient*> observers;
	vector<IClient*>::iterator it;
	
public:
	ConcretePart(PartData);
	ConcretePart& operator=(const ConcretePart&);
	int getQuantity();
	string getName();
	string getManufacturer();
	string getCarBrand();
	int getPrice();
	void setQuantity(int);
	PartData& getData();
	int getID();
	bool operator==(ConcretePart&);
	void addObserver(IClient* observer);
	void removeObserver(IClient* observer);
	void notifyObservers();
	vector<IClient*>getObserverList();
	void addObserverAndUpdateFile(IClient*, int, ConcretePart&);
};
