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

struct classcomp {
	bool operator()(const int& i, const int& j) {
		return (i > j);
	}
};

void OrderProcessing::orderOrdersByMoreDeliveries() {
	map<int, int, classcomp> priorityMap;
	map<int, map<Item, int> >::iterator it;
	for(it = placedOrders.begin(); it != placedOrders.end(); ++it) {
		int orderId = it->first;
		map<Item, int> m = it->second;
		map<Item, int>::iterator it2;
		int totalCnt = 0;
		for (it2 = m.begin(); it2 != m.end(); ++it2) {
			totalCnt += it2->second;
		}
		priorityMap.insert(make_pair(totalCnt, orderId));
	}
	cout << "Printing orders by priority.." << endl;
	map<int, int>::iterator it3;
	for (it3 = priorityMap.begin(); it3 != priorityMap.end(); ++it3) {
		cout << "Order ID: " << it3->first << " Total Items: " << it3->second << endl;
	}
}

void OrderProcessing::orderOrdersByLesserDelay() {

}

OrderProcessing::~OrderProcessing()
{
	instanceFlag = false;
}
