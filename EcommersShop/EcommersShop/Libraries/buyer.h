

#include<iostream>
using namespace std;
#include<string.h>
#include <cstring>

#include"user.h"
#include"addres.h"
#include"item.h"
#include"cart.h"

#ifndef BUYER_H
#define BUYER_H

class Buyer : public User
{
private: 

	Cart* cart;
	Cart** order_history;
	int max_carts = 2;
	int num_of_carts = 0;


public:

	/*Buyer() = default;*/
	Buyer(const char* name, const char* password, const Addres& add);
	/*~Buyer();*/
	Buyer(const Buyer& other);


	Cart* get_cart();                    //not const because we want to change the current cart.
	Cart** get_order_history()           const;
	int get_max_carts()                  const;
	int get_num_of_carts()               const;


	const Buyer& operator=(const Buyer& other);
	bool operator+=(const Item& NewItem);
	friend ostream& operator<<(ostream& os, const Buyer& buyer);
	bool operator>(Buyer& b);

	bool buy_the_cart();
	
};

#endif // BUYER_H
