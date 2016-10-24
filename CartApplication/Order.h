#pragma once
#include <map>
using namespace std;
#include "Cart.h"

class Order {
	private:
		static int orderCnt;
		static map<int, int> orderUserMap;
		int order_id;
		int user_id;
		Cart *cart;

	public:
		Order(int uid, Cart *c);

		bool payment();

		void placeOrder();

		void processOrder();

		~Order();
};
