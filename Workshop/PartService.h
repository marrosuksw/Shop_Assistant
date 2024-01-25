#include"PartsDatabase.h"

class PartService {
private:
	PartsDatabase& partsDatabase = partsDatabase.getInstance();

public:
	void displayParts();

	ConcretePart addQuantity();
};
