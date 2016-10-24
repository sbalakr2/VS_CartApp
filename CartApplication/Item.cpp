#include "stdafx.h"
#include "Item.h"
#include <string>
using namespace std;

Item::Item(int id, string n) : item_id(id), name(n)
{
}

bool Item::operator< (const Item& second) const {
	return item_id < second.item_id;
}

Item::~Item()
{
}
