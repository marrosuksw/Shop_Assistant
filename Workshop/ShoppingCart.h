#include"PartService.h"


class ShoppingCart {
private:
	list<ConcretePart> cart;
public:
	void addToCart(ConcretePart&);
	void removeFromCart(ConcretePart&);
	list<ConcretePart> getCart();
};