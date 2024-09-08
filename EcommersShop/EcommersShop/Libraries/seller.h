#pragma once

#pragma warning(disable: 4996)

#include<iostream>
using namespace std;
#include<string.h>
#include <cstring>

#include"user.h"
#include"addres.h"
#include"item.h"

#ifndef SELLER_H
#define SELLER_H

class Seller : public User
{
private:

	Item** items_for_sale;
	int max_items = 2;
	int num_of_items = 0;

public:


	Seller(const char* name, const char* password, const Addres& add); //constractor
	Seller(const Seller& other); //cpoy constractor
	//~Seller(); //delete func

	int get_max_items()             const;
	int get_num_of_items()          const;

	const Seller& operator=(const Seller& other);
	friend ostream& operator<<(ostream& os, const Seller& seller);
	virtual bool operator+=(const Item& NewItem);
	
};

#endif // SELLER_H

