#include "stdafx.h"
#include "User.h"
#include "Order.h"


User::User(int id, string n) : user_id(id), name(n) {
	cart = new Cart(id);
	//cart.setCartId(id);
}

void User::placeOrder() {
	Order newOrder(user_id, cart);
	newOrder.placeOrder();
}

User::~User()
{
}
