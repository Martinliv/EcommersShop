#pragma warning(disable: 4996)

#include<iostream>
using namespace std;
#include<string.h>
#include <cstring>

#include"addres.h"
#include"user.h"

//////////////////////c'tor & d'tor////////////
User::User(const char* name, const char* password, const Addres& add): add(add)
{
	set_name(name);
	set_password(password);
}
User::User(const User& other):name(NULL), password(NULL), add(other.add)
{
	*this = other;
}
//User:: ~User()
//{
//	delete[] name;
//	delete[] password;
//}

///////////////////////////////////////////////

//////////////////////geters//////////////////
const char* User::get_name() const
{
	return name;
}
const char* User::get_password() const
{
	return password;
}
const Addres& User::get_add() const
{
	return add;
}
///////////////////////////////////////////////////////////////


/////////////////////////////seters///////////////////////////
bool User::set_name(const char* name)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	return true;
}
bool User:: set_password(const char* password)
{
	this->password = new char[strlen(password) + 1];
	strcpy(this->password, password);
	return true;
}
//////////////////////////////////////////////////////////////

////////////////////methods///////////////////////////////////
ostream& operator<<(ostream& os, const User& user)
{
	os << "Name: " << user.name << "Password: " << user.password << "\n" << user.add << endl;
	return os;
}
const User& User:: operator=(const User& other)
{
	if (this != &other)
	{
		delete[]name;
		name = strdup(other.name);
		delete[]password;
		password = strdup(other.password);

	}
	return *this;
}
