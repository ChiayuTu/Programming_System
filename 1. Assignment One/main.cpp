#include <iostream>
#include <cstring>
#include "module.h"

using namespace std;

void product_manage_option(ProductManage & one_product, ScheduleProduct & one_schedule);

int main()
{
	ScheduleProduct one_schedule;

	ProductManage one_product;
	//----------------------------------------------------------------	
	
	product_manage_option(one_product, one_schedule);
	/*
	int option = 0;

	cout << "Select an option what you want to do";
	cout << endl;
	cout << "#1 - The distribution outlet" << endl;
	cout << "#2 - Product" << endl;
	cout << "#3 - Quit" << endl;
	cout << endl;

	cin >> option;

	//If the user enters an invalid option
	while(cin.fail())
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Please enter a valid option" << endl;
		cin >> option;
	}
	cin.clear();
	cin.ignore(100, '\n');

	switch(option)
	{
		case 1:
			//Select the distribution outlet
			//There will choose a distribution 
			cout << "Loading the distribution outlet Module";
			cout << endl;

			product_manage_option(one_product);

			break;

		case 2:
			//Creat the product 
			//The product should include some information
			cout << "Loading creating product Module";
			cout << endl;

			break;

		case 3:
			cout << "Quit the system";
			cout << endl;

			break;
	}
	*/

}

void product_manage_option(ProductManage & one_product, ScheduleProduct & one_schedule)
{
	char * name = new char[300];
	int distribution_type = 0;
	int Nation_distribution_option = 0;
	int Local_distribution_option = 0;
	bool success = false;

	do
	{
		cout << "Select a distribution type: " << endl;
		cout << "#1 - Nation distribution" << endl;
		cout << "#2 - Local  distribution" << endl;
		cout << "#3 - Quit" << endl;
		cout << endl;

		cin >> distribution_type;

		while(cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Please enter valid distribution type(1-2)";
			cin >> distribution_type;
		}
		cin.clear();
		cin.ignore(100, '\n');

		if(distribution_type == 1)
		{
			cout << "Select a Nation distribution option: " << endl;
			cout << endl;
			cout << "#1 - Add a Nation distribution name" << endl;
			cout << "#2 - Display all" << endl;
			cout << "#3 - Change Nation distribution information" << endl;
			cout << endl;

			cin >> Nation_distribution_option;

			while(cin.fail())
			{
				cin.clear();
				cin.ignore(100, '\n');
				cout << "Please select a valid option";
				cin >> Nation_distribution_option;
			}
			cin.clear();
			cin.ignore(100, '\n');

			if(Nation_distribution_option == 1)
			{
				//ScheduleProduct one_schedule;
				Product new_product;
				cout << "Enter a product name: " << endl;
				cin.get(name, 300);
				cin.clear();
				cin.ignore(100, '\n');
				new_product.change_name(name);

				one_schedule.change_priority();
				one_schedule.change_description();
				new_product.change_delivery();

				cout << "Product add" << endl;

				one_product.add_NationDistribution(new_product);
			}else if(Nation_distribution_option == 2)
			{
				//ScheduleProduct one_schedule;
				one_product.display_NationDistribution();
				one_schedule.display();
			}else if(Nation_distribution_option == 3)
			{
				cout<< "Enter the changed name: " << endl;
				cin.get(name, MAX_CHAR);
				cin.ignore(MAX_CHAR);

				success = one_product.change_NationDistribution(name);

				if(success)
				{
					cout << "change successfully" << endl;
				}

			}
		}
		if(distribution_type == 2)
		{
			cout << "Select a Local distribution option: " << endl;
			cout << endl;
			cout << "#1 - Add a Local distribution name" << endl;
			cout << "#2 - Display all" << endl;
			cout << "#3 - Change Local distribution information" << endl;
			cout << endl;

			cin >> Local_distribution_option;

			while(cin.fail())
			{
				cin.clear();
				cin.ignore(100, '\n');
				cout << "Please select a valid option";
				cin >> Local_distribution_option;
			}
			cin.clear();
			cin.ignore(100, '\n');

			if(Local_distribution_option == 1)
			{
				Product new_product;
				cout << "Enter a product name: " << endl;
				cin.get(name, 300);
				cin.clear();
				cin.ignore(100, '\n');

				one_schedule.change_priority();
				one_schedule.change_description();

				//new_product.change_name(name);
				new_product.change_delivery();

				cout << "Product add" << endl;

				one_product.add_LocalDistribution(new_product);
			}else if(Local_distribution_option == 2)
			{
				one_product.display_LocalDistribution();
				one_schedule.display();
			}else if(Local_distribution_option == 3)
			{
				cout<< "Enter the changed name: " << endl;
				cin.get(name, MAX_CHAR);
				cin.ignore(MAX_CHAR);

				success = one_product.change_LocalDistribution(name);

				if(success)
				{
					cout << "change successfully" << endl;
				}

			}
		}

		cout << "Select a distribution type: " << endl;
		cout << "#1 - Nation distribution" << endl;
		cout << "#2 - Local  distribution" << endl;
		cout << endl;

		cin >> distribution_type;

		while(cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Please enter valid distribution type(1-2)";
			cin >> distribution_type;
		}
		cin.clear();
		cin.ignore(100, '\n');
	}while(distribution_type < 3);
}






























