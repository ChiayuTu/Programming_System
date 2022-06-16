#include <iostream>
#include "phone.h"

void edit_a_device_option(device_info *& new_device);
void add_a_device_option(tree_manager & a_manager);


int main()
{

	tree_manager a_manager;
	string_data temp;

	int option = 0;

	while(option != 5)
	{
		cout << endl;
		cout << "Select a cellphone device:" << endl
			<< "#1 - Add a device information" << endl
			<< "#2 - Display all devices information" << endl
			<< "#3 - Remove a device information" << endl
			<< "#4 - Edit a device information" << endl
			<< "#5 - Quit" << endl << endl;
		cin >> option;

		while(cin.fail()) {

			cin.clear();
			cin.ignore(size, '\n');
			cout << "Please enter a valid option 1-5. " << endl;
			cin >> option;
		}
		cin.clear();
		cin.ignore(size, '\n');

		switch(option)
		{
			case 1:
				add_a_device_option(a_manager);
				break;
			case 2:
				cout << a_manager;
				break;
			case 3:
				{
					cout << "Enter the name of the device to remove" << endl;

					cin >> temp;
					cin.ignore(size, '\n');
					a_manager.remove_info(temp);
				}
				break;
			case 4:
				{
					device_info * new_device = NULL;

					cout << "Enter the name of the device to edit" << endl;
					cin >> temp;
					cin.ignore(size, '\n');

					new_device = a_manager.retrieve_info(temp);

					if(new_device)
					{
						edit_a_device_option(new_device);
					}else
					{
						cout << "There is no device matched to this name" << endl;
					}
				}
				break;
			case 5:
				cout << "Quit" << endl;
				break;
			default:
				cout << "Enter an option between 1-5" << endl;
		}
	}

	return 0;
}

void add_a_device_option(tree_manager & a_manager)
{
	node * new_device = NULL;

	int option = 0;

	cout << "Choose a type of device to add" << endl
		<< "#1 - Land line phone" << endl
		<< "#2 - Satellite phone" << endl
		<< "#3 - Cellphone" << endl << endl;

	cin >> option;

	while(cin.fail()) {
		cin.clear();
		cin.ignore(size, '\n');
		cout << "Please enter a valid option: ";
		cin >> option;
	}

	cin.clear();
	cin.ignore(size, '\n');

	switch(option)
	{
		case 1:
			new_device = new land_line;
			break;
		case 2:
			new_device = new satellite;
			break;
		case 3:
			new_device = new cellphone;
			break;
		default:
			cout << "Enter an option between 1-3" << endl;
	}

	new_device->set_name();
	new_device->set_num();
	new_device->set_description();

	a_manager += new_device;
}

void edit_a_device_option(device_info *& new_device)
{
	string_data temp;
	int option_one = 0;
	int option_two = 0;

	cout << "Choose an option" << endl
		<< "#1 - Change the description" << endl
		<< "#2 - Change the number of device" << endl
		<< "#3 - Change the name of device" << endl
		<< "#4 - Change other information" << endl << endl;

	cin >> option_one;

	while(cin.fail()) {
		cin.clear();
		cin.ignore(size, '\n');
		cout << "Please enter a valid option... ";
		cin >> option_one;
	}

	cin.clear();
	cin.ignore(size, '\n');

	switch (option_one)
	{
		case 1:
			new_device->set_description();
			break;
		case 2:
			new_device->set_num();
			break;
		case 3:
			new_device->set_name();
			break;
		case 4:
			{
				cout << "Select an option" << endl
					<< "#1 - Land line option" << endl
					<< "#2 - Satellite option" << endl
					<< "#3 - cellphone option" << endl << endl;

				cin >> option_two;

				while(cin.fail()) {
					cin.clear();
					cin.ignore(size, '\n');
					cout << "Please enter valid option.";
					cin >> option_two;
				}

				cin.clear();
				cin.ignore(size, '\n');

				switch(option_two)
				{
					case 1:
						{
							land_line * temp = NULL;
							temp = dynamic_cast < land_line*> (new_device);

							if(temp)
							{
								temp->set_land_line_price();
								temp->set_network_plan();
							}else
							{
								cout << "You do not have a record" << endl;
							}
						}

						break;
					case 2:
						{
							satellite * temp = NULL;
							temp = dynamic_cast < satellite*> (new_device);

							if(temp)
							{
								temp->set_satellite_company();
								temp->set_satellite_price();
							}else
							{
								cout << "You do not have a record" << endl;
							}
						}

						break;
					case 3:
						{
							cellphone * temp = NULL;
							temp = dynamic_cast < cellphone*> (new_device);

							if(temp)
							{
								temp->set_data_plan();
								temp->set_duration();
							}else
							{
								cout << "You do not have a record" << endl;
							}
						}

						break;
					default:
						cout << "Select an option between 1-3" << endl;
				}
			}
			break;
		default:
			cout << "Selcet an option between 1- 4" << endl;
	}
}
















