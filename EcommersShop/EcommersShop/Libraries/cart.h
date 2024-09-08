#pragma once

#pragma warning(disable: 4996)

#include<iostream>
using namespace std;
#include<string.h>
#include <cstring>

#include"item.h"
#include"cart.h"

#ifndef CART_H
#define CART_H

class Cart
{
private:

	static int serial_generator;
	int serial_num;
	int total_price = 0;
	Item** cart;
	int max_items = 2;
	int num_of_items = 0;

public:

	/*Cart() = default;*/
	Cart();
	/*~Cart();*/
	Cart(const Cart& other);

	int get_total_price()            const;
	int get_max_items()              const;
	int get_num_of_items()           const;
	


	const Cart& operator=(const Cart& other);
	friend ostream& operator<<(ostream& os, const Cart& cart);

	bool add_item_to_cart(const Item& NewItem);
};

#endif // CART_H


