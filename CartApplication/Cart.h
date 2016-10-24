#pragma once
using namespace std;
#include "Item.h"

class Cart {
private:
	int user_id;
	int totalNoOfItems;
	map<Item, int> items;

public:
	Cart();
	Cart(int uid);

	void setCartId(int id) { user_id = id; }

	map<Item, int> getCartItems() { return items; }

	void addItem(Item i);

	void updateItem(Item i, int num);

	void removeItem(Item i);

	int getTotalNumberOfItems() {
		return totalNoOfItems;
	}

	int getUniqueItems() {
		return items.size();
	}

	bool isEmpty() {
		return items.empty();
	}

	void displayCartItems();

	~Cart();
};