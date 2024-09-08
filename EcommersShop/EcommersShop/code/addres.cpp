#pragma warning(disable: 4996)

#include<iostream>
using namespace std;
#include<string.h>
#include <cstring>

#include"addres.h"

//////////////////////c'tor & d'tor////////////

Addres::Addres(const char* street, int house_num, const char* city, const char* country)
{
	set_street(street);
	set_house_num(house_num);
	set_city(city);
	set_country(country);
}
Addres::Addres(const Addres& other): street(NULL), city(NULL), country(NULL)
{
	*this = other;
	
}
//Addres::~Addres()
//{
//	delete[] street;
//	delete[] city;
//	delete[] country;
//}

///////////////////////////////////////////////

//////////////////////geters//////////////////
const char* Addres::get_street()    const
{
	return street;
}
int Addres::get_house_num()          const
{
	return house_num;
}
const char* Addres::get_city()      const
{
	return city;
}
const char* Addres::get_country()   const
{
	return country;
}
///////////////////////////////////////////////////////////////


/////////////////////////////seters///////////////////////////
bool Addres::set_street(const char* street)
{
	this->street = new char[strlen(street) + 1];
	strcpy(this->street, street);
	return true;
}
bool Addres::set_house_num(int house_num)
{
	this->house_num = house_num;
	return true;
}
bool Addres::set_city(const char* city)
{
	this->city = new char[strlen(city) + 1];
	strcpy(this->city, city);
	return true;
}
bool Addres::set_country(const char* country)
{
	this->country = new char[strlen(country) + 1];
	strcpy(this->country, country);
	return true;
}
//////////////////////////////////////////////////////////////

////////////////////methods///////////////////////////////////
ostream& operator <<(ostream& os, const Addres& addres)
{
	os << "Addres is: " << addres.street << " " << addres.house_num << " , " << addres.city << " , " << addres.country << "." << endl;
	return os;
}
const Addres& Addres:: operator=(const Addres& other)
{
	if (this != &other)
	{
		house_num = other.house_num;
		delete[] street;
		street = strdup(other.street);
		delete[] city;
		city = strdup(other.city);
		delete[] country;
		country = strdup(other.country);
	}
	return *this;
}