#pragma once

#pragma warning(disable: 4996)

#include<iostream>
using namespace std;
#include<string.h>
#include <cstring>

#include"item.h"
#include"cart.h"


int Cart::serial_generator = 999;

//////////////////////c'tor & d'tor//////////////////////
Cart::Cart() : serial_num(++serial_generator)
{
	total_price = 0;
	max_items = 2;
	num_of_items = 0;
	cart = new Item * [max_items];
}
Cart::Cart(const Cart& other) :cart(NULL), serial_num(++serial_generator)
{
	*this = other;
	
}
//Cart::~Cart()
//{
//	for (int i = 0; i < numOfItems; i++)
//	{
//		delete cart[i];
//	}	
//	delete[]cart;
//}
///////////////////////////////////////////////////////

///////////////////////geters///////////////////////////
int Cart::get_total_price()    const
{
	return total_price;
}
int Cart::get_max_items()      const
{
	return max_items;
}
int Cart::get_num_of_items()    const
{
	return num_of_items;
}



///////////////////////////////////////////////////////


///////////////////////methods////////////////////////
bool Cart::add_item_to_cart(const Item& NewItem)
{
	if (num_of_items == max_items)
	{
		max_items *= 2;
		Item** temp = new Item * [max_items];
		for (int i = 0; i < num_of_items; i++)
		{
			temp[i] = cart[i];
		}
		delete[]cart;
		cart = temp;
	}
	cart[num_of_items] = new Item(NewItem);
	total_price = total_price + NewItem.get_item_price();
	num_of_items++;

	return true;
}

ostream& operator<<(ostream& os, const Cart& cart)
{
	os << "\nThe Cart (serial number: " << cart.serial_num << ") " << " includes: " << endl;
	for (int i = 0; i < cart.num_of_items; i++)
	{
		os << i + 1 << "." << *cart.cart[i] << endl;
	}
	os << "\nTotal price : " << cart.total_price << " $" << endl;
	return os;
}
const Cart& Cart::operator=(const Cart& other)
{
	if (this != &other)
	{
		serial_num = other.serial_num;
		total_price = other.total_price;
		max_items = other.max_items;
		num_of_items = other.num_of_items;
		for (int i = 0; i < num_of_items; i++)
		{
			delete cart[i];
		}	
		delete[]cart;
		cart = other.cart;
	}
	return *this;
}
///////////////////////////////////////////////////////
