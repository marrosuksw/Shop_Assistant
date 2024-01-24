#include"ConcretePart.h"

class PartsDatabase {
private:
	vector<ConcretePart> partsBase;
	string statFilename = "partdb.txt";
	vector<ConcretePart>::iterator it;
	PartsDatabase();
	~PartsDatabase();
public:
	PartsDatabase(PartsDatabase&) = delete;
	void operator=(const PartsDatabase&) = delete;
	static PartsDatabase& getInstance(){
		static PartsDatabase instance;
		return instance;
	}
	void updateCollection();
	void addPartToBase(ConcretePart&);
	vector<ConcretePart> fetchPartsCollection();
	void print();
	void changeInCollection(ConcretePart);
	bool checkIfPartExists(int);
	ConcretePart getConcPartThroughID(int);
	void overwriteCollection();

};
