#include"IClient.h"

struct PartData {
	string carBrand;
	string name;
	string manufacturer;
	int price;
	int quantity;
	int partID;
	bool operator==(const PartData& elem);
};



