#pragma once

#pragma warning(disable: 4996)

#include<iostream>
using namespace std;
#include<string.h>
#include <cstring>

#include"addres.h"
#include"item.h"
#include"cart.h"
#include"buyer.h"

//////////////////////c'tor & d'tor//////////////////////
Buyer::Buyer(const char* name, const char* password, const Addres& add) :User(name,password,add)
{
	order_history = new Cart * [max_carts];
	cart = new Cart();///////////

}
Buyer::Buyer(const Buyer& other) :cart(NULL), order_history(NULL), User(other)
{
	*this = other;
}
//Buyer::~Buyer()
//{
//	delete[]cart;
//	for (int i = 0; i < num_of_carts; i++)
//	{
//		delete order_history[i];
//	}delete[]order_history;
//}
///////////////////////////////////////////////

///////////////////////geters/////////////////
Cart* Buyer::get_cart()
{
	return cart;
}
Cart** Buyer::get_order_history()           const
{
	return order_history;
}
int Buyer::get_max_carts()                   const
{
	return max_carts;
}
int Buyer::get_num_of_carts()                 const
{
	return num_of_carts;
}

///////////////////////////////////////////////


///////////////////////methods/////////////////////////
bool Buyer::operator+=(const Item& NewItem)
{
	cart->add_item_to_cart(NewItem);
	return true;
}

bool Buyer::buy_the_cart()
{
	if (num_of_carts == max_carts)
	{
		max_carts *= 2;
		Cart** temp = new Cart * [max_carts];
		for (int i = 0; i < num_of_carts; i++)
		{
			temp[i] = order_history[i];

		}
		delete[]order_history;
		order_history = temp;

	}
	order_history[num_of_carts] = get_cart();
	num_of_carts++;
	cart = new Cart();

	return true;
}

ostream& operator<<(ostream& os, const Buyer& buyer)
{
	os << "Name: " << buyer.name << ".  Password: " << buyer.password << "." << "\n" << buyer.add << endl;
	os << *buyer.cart << endl;
	os << "-----------------------" << endl;
	return os;
	
}

bool Buyer::operator>(Buyer& b)
{
	if (cart->get_total_price() > b.get_cart()->get_total_price())
	{
		return true;
	}
	else
		return false;
}

const Buyer& Buyer::operator=(const Buyer& other)
{
	if (this != &other)
	{
		User::operator=(other);
		max_carts = other.max_carts;
		num_of_carts = other.num_of_carts;
		delete[]cart;
		cart = other.cart;
		for (int i = 0; i < num_of_carts; i++)
		{
			delete order_history[i];
		}
		delete[]order_history;
		order_history = other.order_history;
	}
	return *this;
}
///////////////////////////////////////////////
