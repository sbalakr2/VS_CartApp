#include "stdafx.h"
#include "OrderProcessing.h"

map< int, map<Item, int> > OrderProcessing::placedOrders;
bool OrderProcessing::instanceFlag = false;
OrderProcessing* OrderProcessing::allOrders = NULL;


OrderProcessing* OrderProcessing::getInstance() {
	if (!instanceFlag) {
		allOrders = new OrderProcessing();
		instanceFlag = true;
		return allOrders;
	}
	else {
		return allOrders;
	}
}

void OrderProcessing::addOrder(int oid, Cart *c) {
	placedOrders.insert(make_pair(oid, c->getCartItems()));
	cout << "Adding order.." << endl;

}

void OrderProcessing::displayAllPlacedOrders() {
	cout << "Displayed all outstanding orders.." << endl;
	cout << "-------------------------------------------------" << endl;
	map< int, map<Item, int> >::iterator it;
	for (it = placedOrders.begin(); it != placedOrders.end(); ++it) {
		cout << "Order ID: " << it->first << endl;
		map<Item, int> m = it->second;
		map<Item, int>::iterator it2;
		cout << "Items: " << endl;
		int total = 0;
		for (it2 = m.begin(); it2 != m.end(); ++it2) {
			Item item = it2->first;
			cout << "Item ID: " << item.getItemId() << "   |    Name: " << item.getName()
				<< "   |    Nos: " << it2->second << endl;
			total += it2->second;
		}
		cout << "Total number of items: " << total << endl;
		cout << "-------------------------------------------------" << endl;
	}
}

void OrderProcessing::orderOrdersByMoreDeliveries() {
	placedOrders
}

void OrderProcessing::orderOrdersByLesserDelay() {

}

OrderProcessing::~OrderProcessing()
{
	instanceFlag = false;
}
