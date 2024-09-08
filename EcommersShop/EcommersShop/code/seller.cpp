#pragma warning(disable: 4996)

#include<iostream>
using namespace std;
#include<string.h>
#include <cstring>

#include"addres.h"
#include"item.h"
#include"seller.h"

//////////////////////c'tor & d'tor//////////////////////
Seller::Seller(const char* name, const char* password, const Addres& add) :User(name, password, add)
{
	max_items = 2;
	num_of_items = 0;
	items_for_sale = new Item * [max_items];
}
Seller::Seller(const Seller& other) :items_for_sale(NULL),User(other)
{
	*this = other;
	
}
//Seller::~Seller()
//{
//	for (int i = 0; i < num_of_items; i++)
// {
//		delete items_for_sale[i];
// }
//	delete[]items_for_sale;
//}
///////////////////////////////////////////////

///////////////////////geters/////////////////
int Seller:: get_max_items()             const
{
	return max_items;
}
int Seller:: get_num_of_items()          const
{
	return num_of_items;
}
/////////////////////////////////////////////////

///////////////////////methods/////////////////////////
bool Seller::operator+=(const Item& NewItem)
{
	if (num_of_items == max_items)
	{
		max_items *= 2;
		Item** temp = new Item * [max_items];
		for (int i = 0; i < num_of_items; i++)
		{
			temp[i] = items_for_sale[i];

		}
		delete[]items_for_sale;
		items_for_sale = temp;
	}
	items_for_sale[num_of_items] = new Item(NewItem);
	num_of_items++;

	return true;
}
ostream& operator<<(ostream& os, const Seller& seller)
{
	os << "Name: " << seller.name << ".  Password: " << seller.password << "." << "\n" << seller.add << endl
	<< "Sellers Items Are: " << endl;
	if (seller.num_of_items == 0)
	{
		os << "NO Items!!" << endl;
		os << "--------------------" << endl;
	}
	else
	{
		for (int i = 0; i < seller.num_of_items; i++)
		{
			os << i + 1 << "." << *seller.items_for_sale[i] << endl;
			os << "---------------------" << endl;
		}
	}
	return os;
}
const Seller& Seller:: operator=(const Seller& other)
{
	if (this != &other)
	{
		User::operator=(other);
		max_items = other.max_items;
		num_of_items = other.num_of_items;
		for (int i = 0; i < num_of_items; i++)
		{
			delete items_for_sale[i];
		}
		delete[]items_for_sale;
		items_for_sale = other.items_for_sale;
	}
	return *this;
}
//////////////////////////////////////////////////////