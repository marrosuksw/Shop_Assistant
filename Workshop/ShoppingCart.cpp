#include"ShoppingCart.h"

void ShoppingCart::addToCart(ConcretePart& part) {
	cart.push_back(part);
}
void ShoppingCart::removeFromCart(ConcretePart& part) {
    cart.erase(std::remove_if(cart.begin(), cart.end(),
        [&part](ConcretePart& cartPart) {
            return cartPart.getID() == part.getID();
        }),
        cart.end());
}
list<ConcretePart> ShoppingCart::getCart() {
    return cart;
}