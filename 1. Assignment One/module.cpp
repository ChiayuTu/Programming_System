//module.cpp
#include <cstring>
#include "module.h"

//Module class function
//----------------------------------------------------------------	
//Default constructor, let protected data member product_name equals to NULL
Module::Module()
{
	product_name = NULL;
}

//Destructor, deallocate char * product_name
Module::~Module()
{
	if(product_name)
		delete [] product_name;
	product_name = NULL;
}

//Copy constructor for Module class that copies a product name
Module::Module(const Module & obj)
{
	if(obj.product_name)
	{
	//make sure there is a product name to copy so the pointer isn't NULL, to avoid 
	//dereferencing a NULL pointer
		product_name = new char[strlen(obj.product_name) + 1];
		strcpy(product_name, obj.product_name);
	}else
	{
		product_name = NULL;
	}
}

//Change the name of the product
void Module::change_name(const char * new_name)
{
	if(product_name)
	{
		delete [] product_name;
	}
	//cout << "Change the product name" << endl;
	product_name = new char[strlen(new_name) + 1];
	strcpy(product_name, new_name);
}

//compare the product_name that already exists to the to_compare name
//Return true if the name is matched and return the false if not
bool Module::compare_name(const char * to_compare)
{
	if(strcmp(to_compare, product_name)+ 1)
	{
		return true;
	}else
	{
		return false;
	}
}

//Display the product name
void Module::display()
{
	if(product_name)
	{
		cout << "The product name is: " << product_name << endl;
	}else
	{
		cout << "There isn't any product name" << endl;
	}
}

//ScheduleProduct class functions
//----------------------------------------------------------------	
//Constructor
ScheduleProduct::ScheduleProduct()
{
	priority = 0;
	description = NULL;
}

//Copy constructor
ScheduleProduct::ScheduleProduct(const ScheduleProduct & obj): Module(obj)
{
	//If there is a description, copy it.
	//If not, set it to NULL
	if(obj.description)
	{
		description = new char[strlen(obj.description) + 1];
		strcpy(description, obj.description);
	}else
	{
		description = NULL;
	}

	//copy int priority
	priority = 0;
}

//Destructor
ScheduleProduct::~ScheduleProduct()
{
	if(description)
		delete [] description;
	description = NULL;
}

//Change the product's priority
void ScheduleProduct::change_priority()
{
	int temp = 0;
	
	cout << "Set the shipping priority for the product" << endl;
	cout << "Please using an integer value from 1 to 5" << endl;
	cin >> temp;
	cin.ignore(100, '\n');

	if(temp > 0 && temp < 6)
	{
		priority = temp;
	}else
	{
		cout << "Error, invalid entry";
	}
}

//Change the product's description
void ScheduleProduct::change_description()
{
	cout << "Enter the description of this product" << endl;
	//delete the privious array
	if(description)
	{
		delete [] description;
	}

	//Set a new description
	description = new char[MAX_CHAR + 1];
	cin.get(description, MAX_CHAR);
	cin.ignore(100, '\n');
}

//Display 
void ScheduleProduct::display()
{
	//cout << "The product name is:             ";
	//Module::display();
	//cout << endl;

	cout << "The priority of this product is: " << endl << priority <<endl;
	cout << "The description of this product: " << endl << description << endl;

}
















































