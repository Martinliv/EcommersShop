#pragma once

#pragma warning(disable: 4996)

#include<iostream>
using namespace std;
#include<string.h>
#include <cstring>

#ifndef ADDRES_H
#define ADDRES_H

class Addres
{
private:

	char* street;
	int house_num;
	char* city;
	char* country;

public:

	/*Addres() = default;*/
	Addres(const char* street, int house_num, const char* city, const char* country); //constractor
	Addres(const Addres& other); //copy constractor
	//~Addres(); //delete func

	const char* get_street()  const;
	int get_house_num()       const;
	const char* get_city()    const;
	const char* get_country() const;

	bool set_street(const char* street);
	bool set_house_num(int house_num);
	bool set_city(const char* city);
	bool set_country(const char* country);

	const Addres& operator=(const Addres& other);
	friend ostream& operator <<(ostream& os, const Addres& addres);
};

#endif // ADDRES_H
