#include"ConcretePart.h"

class PartsDatabase {
private:
	vector<ConcretePart> partsBase;
	string statFilename = "partdb.txt";
	vector<ConcretePart>::iterator it;
public:

	void updateCollection();
	void addPartToBase(ConcretePart&);
	vector<ConcretePart> fetchPartsCollection();
	void print();

};
