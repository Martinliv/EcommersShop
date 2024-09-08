#pragma once

#pragma warning(disable: 4996)

#include<iostream>
using namespace std;
#include<string.h>
#include <cstring>

#include"user.h"
#include"seller.h"
#include"buyer.h"

#ifndef SYSTEM_H
#define SYSTEM_H

class System
{
private:

	int num_of_buyers = 0, max_num_of_buyers = 2;
	int num_of_sellers = 0, max_num_of_sellers = 2;
	int num_of_items = 0, max_num_of_items = 2;
	Buyer** list_of_buyers;
	Seller** list_of_sellers;
	Item** list_of_items_for_sale;

public:

	System();
	/*~System();*/
	
	//geters and seters
	Buyer** get_list_of_buyers()          const;
	Seller** get_list_of_sellers()        const;
	Item** get_list_of_items_for_sale()   const;
	int get_num_of_buyers()               const;
	int get_max_num_of_buyers()           const;
	int get_num_of_sellers()              const;
	int get_max_num_of_sellers()          const;
	int get_num_of_items()                const;
	int get_max_num_of_items()            const;

	bool set_num_of_buyers(int num_of_buyers);
	bool set_max_num_of_buyers(int max_num_of_buyers);
	bool set_num_of_sellers(int num_of_sellers);
	bool set_max_num_of_sellers(int max_num_of_sellers);
	bool set_num_of_items(int num_of_items);
	bool set_max_num_of_items(int max_num_of_items);



	//methods
	void read_user_det(char user_name[], char user_password[], char street[], int& houseNum, char city[], char country[])    const;
	void read_item_det(char item_name[], int& item_price, Category& category)                                                const;
	void identity_verification(char name[], char password[])                                                                 const;

	Seller* find_seller_byName_and_byPassword(const char* seller_name, const char* seller_password)            const;
	Buyer* find_buyer_byName_and_byPassword(const char* buyer_name, const char* buyer_password)                const;
	Item* find_item_from_list_by_number(int choice)                                                            const;

	const System& operator=(const System& other);
	bool operator+=(const Buyer& newbuyer);
	bool operator+=(const Seller& newseller);
	bool operator+=(const Item& newitem);
    
};

#endif // SYSTEM_H

