// CartApplication.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
#include "Cart.h"
#include "User.h"
#include "OrderProcessing.h"

int main() {
	User user1(1, "Sindhu");
	Item i1(11, "book");
	Item i2(12, "pen");
	Item i3(13, "pencil");
	Item i4(14, "bed");
	Item i5(15, "watch");
	Cart *c = user1.getCart();
	c->addItem(i1);
	c->addItem(i2);
	c->addItem(i3);
	c->updateItem(i3, 5);
	c->removeItem(i2);
	c->addItem(i1);

	User user2(2, "Nivi");
	Cart *c2 = user2.getCart();
	c2->addItem(i1);
	c2->updateItem(i1, 3);
	c2->addItem(i2);
	c2->updateItem(i2, 5);

	User user3(3, "Keerthana");
	Cart *c3 = user3.getCart();
	c3->addItem(i5);
	c3->updateItem(i5, 3);
	c3->addItem(i4);

	User user4(4, "Rithika");
	Cart *c4 = user4.getCart();
	c4->addItem(i1);
	c4->updateItem(i1, 2);
	c4->addItem(i4);

	User user5(5, "Sowmi");
	Cart *c5 = user5.getCart();
	c5->addItem(i2);
	c5->updateItem(i2, 10);
	c5->addItem(i5);

	//cout << c->getTotalNumberOfItems() << endl;
	//cout << c->getUniqueItems() << endl;
	//c->displayCartItems();
	// cout << user1.getName() <<"'s cart contains.." << endl;
	// user1.getCart()->displayCartItems();
	//cout << user2.getName() <<"'s cart contains.." << endl;
	//user2.getCart()->displayCartItems();

	user1.placeOrder();
	user2.placeOrder();
	user3.placeOrder();
	user4.placeOrder();
	user5.placeOrder();

	OrderProcessing::displayAllPlacedOrders();
	OrderProcessing::orderOrdersByMoreDeliveries();

	delete c;
	delete c2;
	delete c3;
	return 0;
}

