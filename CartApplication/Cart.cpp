#include "stdafx.h"
#include "Cart.h"


Cart::Cart()
{
	totalNoOfItems = 0;
}

Cart::Cart(int uid) : user_id(uid) { totalNoOfItems = 0; }

void Cart::addItem(Item i) {
	map<Item, int>::iterator it = items.find(i);
	if (it == items.end()) {
		items.insert(pair<Item, int>(i, 1));
	}
	else {
		it->second += 1;
	}
	totalNoOfItems++;
}

void Cart::updateItem(Item i, int num) {
	map<Item, int>::iterator it = items.find(i);
	if (it != items.end()) {
		int prev = it->second;
		it->second = num;
		totalNoOfItems += (num - prev);
	}
}

void Cart::removeItem(Item i) {
	map<Item, int>::iterator it = items.find(i);
	if (it != items.end()) {
		int prev = it->second;
		items.erase(it);
		totalNoOfItems -= prev;
	}
}

void Cart::displayCartItems() {
	map<Item, int>::iterator it;
	//cout << "Cart contains.."<<endl;
	for (it = items.begin(); it != items.end(); ++it) {
		Item item = it->first;
		cout << item.getItemId() << " " << item.getName() << " Count:" << it->second << endl;
	}
}

Cart::~Cart()
{
}
