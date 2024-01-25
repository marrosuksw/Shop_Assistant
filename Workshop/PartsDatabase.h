#include"ConcretePart.h"

class PartsDatabase {
private:
	vector<ConcretePart> partsBase;
	string statFilename = "partdb.txt";
	vector<ConcretePart>::iterator it;
	PartsDatabase();
	~PartsDatabase();
	void updateCollection();
	vector<ConcretePart> fetchPartsCollection();
public:
	PartsDatabase(PartsDatabase&) = delete;
	void operator=(const PartsDatabase&) = delete;
	static PartsDatabase& getInstance(){
		static PartsDatabase instance;
		return instance;
	}
	void print();
	void changeInCollection(ConcretePart);
	bool checkIfPartExists(int);
	ConcretePart getConcPartThroughID(int);
	void overwriteCollection();
};
