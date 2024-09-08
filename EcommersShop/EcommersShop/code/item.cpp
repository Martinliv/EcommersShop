#pragma warning(disable: 4996)

#include<iostream>
using namespace std;
#include<string.h>
#include <cstring>

#include"item.h"

//////////////////////c'tor & d'tor////////////
Item::Item(const char* item_name, int item_price, Category item_category)
{
	set_item_name(item_name);
	set_item_price(item_price);
	set_item_category(item_category);
}
Item::Item(const Item& other): item_name(NULL)
{
	*this = other;
	
}
//Item::~Item()
//{
//	delete[]item_name;
//}
/////////////////////////////////////////////////

///////////////////////geters/////////////////
const char* Item::get_item_name()  const
{
	return item_name;
}
int Item::get_item_price()         const
{
	return item_price;
}
Category Item::get_item_category() const
{
	return item_category;
}

/////////////////////////////////////////////////

/////////////////////seters/////////////////////
bool Item::set_item_name(const char* item_name)
{
	this->item_name = new char[strlen(item_name) + 1];
	strcpy(this->item_name, item_name);
	return true;
}
bool Item::set_item_price(int item_price)
{
	this->item_price = item_price;
	return true;
}
bool Item::set_item_category(Category item_category)
{
	this->item_category = item_category;
	return true;
}
////////////////////////////////////////////////

///////////////////////methods/////////////////////////
ostream& operator<<(ostream& os, const Item& item)
{
	os << "Product Name: " << item.get_item_name() << ". Price: " << item.get_item_price() << endl;
	switch (item.item_category)
	{
	case Electricity:
		os << "Category: Electricity" << endl;
		break;
	case Children:
		os << "Category: Children" << endl;
		break;
	case Office:
		os << "Category: Office" << endl;
		break;
	case Clothing:
		os << "Category: Clothing" << endl;
		break;
	default:
		break;
	}
	return os;

}
const Item& Item:: operator=(const Item& other)
{
	if (this != &other)
	{
		delete[] item_name;
		item_name = strdup(other.item_name);
		item_price = other.item_price;
		item_category = other.item_category;
	}
	return *this;
}
////////////////////////////////////////////////