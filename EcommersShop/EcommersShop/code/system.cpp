#pragma once

#pragma warning(disable: 4996)

#include<iostream>
using namespace std;
#include<string.h>
#include <cstring>

#include"seller.h"
#include"buyer.h"
#include"system.h"

System::System()
{
	num_of_buyers = 0;
	num_of_sellers = 0;
	num_of_items = 0;
	max_num_of_buyers = 2;
	max_num_of_sellers = 2;
	max_num_of_items = 2;
	list_of_buyers = new Buyer * [max_num_of_buyers];
	list_of_sellers = new Seller * [max_num_of_sellers];
	list_of_items_for_sale = new Item * [max_num_of_items];
}
//System::~System()
//{
//	for (int i = 0; i < num_of_buyers; i++)
//	{
//		delete list_of_buyers[i];
//	}
//	delete[]list_of_buyers;
//
//	for (int k = 0; k < num_of_sellers; k++)
//	{
//		delete list_of_sellers[k];
//	}
//	delete[]list_of_sellers;
//
//	for (int j = 0; j < num_of_items; j++)
//	{
//		delete list_of_items_for_sale[j];
//	}
//	delete[] list_of_items_for_sale;
//}

																		   //geters
Buyer** System::get_list_of_buyers()           const
{
	return list_of_buyers;
}
Seller** System::get_list_of_sellers()         const
{
	return list_of_sellers;
}
Item** System::get_list_of_items_for_sale()    const
{
	return list_of_items_for_sale;
}
int System::get_num_of_buyers()                const
{
	return num_of_buyers;
}
int System::get_max_num_of_buyers()            const
{
	return max_num_of_buyers;
}
int System::get_num_of_sellers()               const
{
	return num_of_sellers;
}
int System::get_max_num_of_sellers()           const
{
	return max_num_of_sellers;
}
int System::get_num_of_items()                 const
{
	return num_of_items;
}
int System::get_max_num_of_items()             const
{
	return max_num_of_items;
}
///////////////////////////////////////////////////////////

																		//seters
bool System::set_num_of_buyers(int num_of_buyers)
{
	this->num_of_buyers = num_of_buyers;
	return true;
}
bool System::set_max_num_of_buyers(int max_num_of_buyers)
{
	this->max_num_of_buyers = max_num_of_buyers;
	return true;
}
bool System::set_num_of_sellers(int num_of_sellers)
{
	this->num_of_sellers = num_of_sellers;
	return true;
}
bool System::set_max_num_of_sellers(int max_num_of_sellers)
{
	this->max_num_of_sellers = max_num_of_sellers;
	return true;
}
bool System::set_num_of_items(int num_of_items)
{
	this->num_of_items = num_of_items;
	return true;
}
bool System::set_max_num_of_items(int max_num_of_items)
{
	this->max_num_of_items = max_num_of_items;
	return true;
}
///////////////////////////////////////////////////////////

void System::read_user_det(char user_name[], char user_password[], char street[], int& houseNum, char city[], char country[])  const
{
	cout << "*****************************\n";
	cout << "Enter your name: ";
	cin >> user_name;
	cout << "\nEnter your password: ";
	cin >> user_password;
	cout << "\nEnter your address: ";
	cout << "\nStreet - ";
	cin >> street;
	cout << "\nHouse Number - ";
	cin >> houseNum;
	cout << "\nCity - ";
	cin >> city;
	cout << "\nCountry - ";
	cin >> country;
}

void System::read_item_det(char item_name[], int& item_price, Category& category)  const
{
	int choice;
	cout << "*****************************\n";
	cout << "Enter item's name: ";
	cin >> item_name;
	cout << "\nEnter item's price: ";
	cin >> item_price;
	cout << "\nChoose which category the product belongs to: " << endl;
	cout << "For Electricity press  1." << endl;
	cout << "For Children press  2." << endl;
	cout << "For Office press  3." << endl;
	cout << "For Clothing press  4." << endl;
	cin >> choice;
	category = (Category)choice;
}

void System::identity_verification(char name[], char password[])   const
{
	cout << "Enter your name: ";
	cin >> name;
	cout << "\nEnter your password: ";
	cin >> password;
}


bool System::operator+=(const Buyer& newbuyer)                              //Add buyer to system
{
	if (num_of_buyers == max_num_of_buyers)
	{
		max_num_of_buyers *= 2;
		Buyer** temp = new Buyer * [max_num_of_buyers];
		for (int i = 0; i < num_of_buyers; i++)
		{
			temp[i] = list_of_buyers[i];
		}
		delete[]list_of_buyers;
		list_of_buyers = temp;
	}
	list_of_buyers[num_of_buyers] = new Buyer(newbuyer);
	num_of_buyers++;

	return true;
}

bool System::operator+=(const Seller& newseller)                          //Add seller to system
{
	if (num_of_sellers == max_num_of_sellers)
	{
		max_num_of_sellers *= 2;
		Seller** temp = new Seller * [max_num_of_sellers];
		for (int i = 0; i < num_of_sellers; i++)
		{
			temp[i] = list_of_sellers[i];
		}
		delete[]list_of_sellers;
		list_of_sellers = temp;
	}
	list_of_sellers[num_of_sellers] = new Seller(newseller);
	num_of_sellers++;

	return true;
}

bool System::operator+=(const Item& newitem)                                //Add item to system
{
	if (num_of_items == max_num_of_items)
	{
		max_num_of_items *= 2;
		Item** temp = new Item * [max_num_of_items];
		for (int i = 0; i < num_of_items; i++)
		{
			temp[i] = list_of_items_for_sale[i];
		}
		delete[]list_of_items_for_sale;
		list_of_items_for_sale = temp;
	}
	list_of_items_for_sale[num_of_items] = new Item(newitem);
	num_of_items++;

	return true;
}

Seller* System::find_seller_byName_and_byPassword(const char* seller_name, const char* seller_password)   const        //find seller
{
	for (int i = 0; i < num_of_sellers; i++)
	{
		if (strcmp(list_of_sellers[i]->get_name(), seller_name) == 0 && strcmp(list_of_sellers[i]->get_password(), seller_password) == 0)
		{
			return list_of_sellers[i];
		}
	}return nullptr;


}
Buyer* System::find_buyer_byName_and_byPassword(const char* buyer_name, const char* buyer_password)    const         //find buyer
{
	for (int i = 0; i < num_of_buyers; i++)
	{
		if (strcmp(list_of_buyers[i]->get_name(), buyer_name) == 0 && strcmp(list_of_buyers[i]->get_password(), buyer_password) == 0)
		{
			return list_of_buyers[i];
		}
	}return nullptr;
}

Item* System::find_item_from_list_by_number(int choice)    const                             //find item
{
	if (choice <= num_of_items && choice >= 0)
	{
		return list_of_items_for_sale[choice - 1];
	}return nullptr;

}

const System& System::operator=(const System& other)
{
	return *this;
}



