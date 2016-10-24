#include "stdafx.h"
#include "Order.h"
#include"OrderProcessing.h"
#include <iostream>
using namespace std;

int Order::orderCnt = 100;
map<int, int> Order::orderUserMap;

Order::Order(int uid, Cart *c) : user_id(uid), cart(c) {
	order_id = ++orderCnt;
	orderUserMap.insert(make_pair(uid, order_id));
	cout << "Checking out items for user " << user_id << " under order id " << order_id << endl;
	cart->displayCartItems();
}

bool Order::payment() {
	cout << "Payment Info processing.." << endl;
	return true;
}

void Order::placeOrder() {
	if (this->payment()) {
		cout << "Successfully ordered!" << endl;
		this->processOrder();
	}
	else {
		cout << "Payment failed! Choose another payment option!" << endl;
	}
}
void Order::processOrder() {
	cout << "Order in process..." << endl;
	// OrderProcessing *op = OrderProcessing::getInstance();
	// map< int, map<Item, int> > curOrder;
	// curOrder.insert(make_pair(user_id, cart->getCartItems()));
	// op->addOrder(curOrder);
	OrderProcessing::addOrder(order_id, cart);
}


Order::~Order()
{
	delete cart;
}
