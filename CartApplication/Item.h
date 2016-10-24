#pragma once
#include <string>
using namespace std;

class Item {
private:
	int item_id;
	string name;

public:
	Item(int id, string n);

	int getItemId() { return item_id; }

	string getName() { return name; }

	bool operator< (const Item& second) const;

	~Item();
};