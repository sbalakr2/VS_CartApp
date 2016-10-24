#pragma once
#include <string>
using namespace std;
#include "Cart.h"

class User {
private:
	int user_id;
	string name;
	Cart* cart;

public:
	User(int id, string n);

	int getUserId() { return user_id; }

	string getName() { return name; }

	Cart* getCart() { return cart; }

	void placeOrder();

	~User();
};