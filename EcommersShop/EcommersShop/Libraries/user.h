#pragma once

#pragma warning(disable: 4996)

#include<iostream>
using namespace std;
#include<string.h>
#include <cstring>

#include"addres.h"

#ifndef USER_H
#define USER_H

class User
{
protected:

	char* name;
	char* password;
	Addres add;

public:

	User(const char* name, const char* password, const Addres& add);
	User(const User& other);
	/*~User();*/

	const char* get_name() const;
	const char* get_password() const;
	const Addres& get_add() const;

	bool set_name(const char* name);
	bool set_password(const char* password);

	const User& operator=(const User& other);
	friend ostream& operator<<(ostream& os, const User& user); 
};

#endif // USER_H

