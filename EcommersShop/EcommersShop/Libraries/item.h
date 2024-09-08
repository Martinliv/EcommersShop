#pragma once

#pragma warning(disable: 4996)

#include<iostream>
using namespace std;
#include<string.h>
#include <cstring>


enum Category
{
	Electricity = 1,
	Children,
	Office,
	Clothing,
};

#ifndef ITEM_H
#define ITEM_H

class Item
{
private:

	char* item_name;
	int item_price;
	Category item_category;

public:

	/*Item() = default;*/
	Item(const char* item_name, int item_price, Category item_category); //constractor
	Item(const Item& other); //copy constractor
	//~Item(); //delete func

	const char* get_item_name()     const;
	int get_item_price()            const;
	Category get_item_category()    const;

	bool set_item_name(const char* item_name);
	bool set_item_price(int item_price);
	bool set_item_category(Category item_category);

	const Item& operator=(const Item& other);
	friend ostream& operator<<(ostream& os, const Item& item);
};

#endif // ITEM_H

