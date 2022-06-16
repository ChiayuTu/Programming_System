#include <iostream>
#include "phone.h"

/*
 
	string_data();
	string_data(const string_data & obj);
	~string_data();

	friend ostream & operator << (ostream & out, const string_data & to_display);
	friend istream & operator >> (istream & in, const string_data & to_input);

	bool operator != (const string_data & to_compare);
	bool operator == (const string_data & to_compare);
	bool operator == (const char * to_compare);
	bool operator <= (const string_data & to_compare);
	bool operator >= (const string_data & to_compare);
	bool operator < (const string_data & to_compare);
	bool operator > (const string_data & to_compare);
*/

string_data::string_data():str(0) {}

string_data::~string_data()
{
	if(str)
		delete [] str;
}

string_data::string_data(const string_data & obj)
{
	if(obj.str)
	{
		str = new char[strlen(obj.str) + 1];
		strcpy(str, obj.str);
	}else
		str = NULL;
}

ostream & operator << (ostream & out, const string_data & to_display)
{
	out << to_display.str;
	return out;
}

istream & operator >> (istream & in, string_data & to_input) {

	char temp[100]; 
	in.get(temp, 100, '\n');

	if(to_input.str) 
	{
		delete [] to_input.str;
	}

	to_input.str = new char[strlen(temp) + 1]; 
	strcpy(to_input.str, temp);
	return in; 
}

bool string_data::operator != (const string_data & to_compare)
{
	if (strcmp(str, to_compare.str) != 0) 
		return true;
	else
		return false;	
}

bool string_data::operator == (const string_data & to_compare)
{
	if (strcmp(str, to_compare.str) == 0)
		return true;
	else
		return false;
}

bool string_data::operator == (const char * to_compare)
{	
	if (strcmp(str, to_compare) == 0)
		return true;
	else
		return false;
}

bool string_data::operator <= (const string_data & to_compare)
{
	if (str <= to_compare.str)
		return true;
	else
		return false;
}

bool string_data::operator >= (const string_data & to_compare)
{
	if (str >= to_compare.str)
		return true;
	else
		return false;
}
bool string_data::operator < (const string_data & to_compare)
{
	if (strcmp(str, to_compare.str) < 0)
		return true;
	else
		return false;
}

bool string_data::operator > (const string_data & to_compare)
{
	if (strcmp(str, to_compare.str) > 0)
		return true;
	else
		return false;
}

string_data & string_data::operator = (const string_data& obj)
{
	if(this == & obj)
		return *this;

	if(obj.str)
	{
		str = new char[strlen(obj.str) + 1];
		strcpy(str, obj.str);
	}else
		str = NULL;

	return *this;
}



















