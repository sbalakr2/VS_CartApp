#pragma once
#include <map>
using namespace std;
#include "Cart.h"
#include "Item.h"

class OrderProcessing {
	private:
		static bool instanceFlag;
		static map< int, map<Item, int> > placedOrders;
		static OrderProcessing *allOrders;
		//OrderProcessing() {  }

	public:
		static OrderProcessing* getInstance();

		static void addOrder(int oid, Cart *c);

		static void displayAllPlacedOrders();

		static void orderOrdersByMoreDeliveries();

		static void orderOrdersByLesserDelay();

		~OrderProcessing();
};
