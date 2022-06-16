#include <iostream>
#include "module.h"

void schedule_add_option(schedule_manager & a_manager);
void schedule_edit_option(schedule *& a_schedule);

int main()
{
	schedule_manager a_manager;

	char * schedule_name = new char[max_char];
	int option = 0;
	do 
	{
		cout << "Choose a schedule" << endl
			<< "#1 - Display all schedule" << endl
			<< "#2 - Add a schedule" << endl
			<< "#3 - Remove a schedule" << endl
			<< "#4 - Edit a schedule" << endl
			<< "#5 - Quit" << endl;

		cin >> option;
		while(cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Enter a valid number" << endl;
			cin >> option;
		}
		cin.clear();
		cin.ignore(100, '\n');

		if(option == 1)
		{
			a_manager.display();
		}else if(option == 2)
		{
			schedule_add_option(a_manager);
		}else if(option == 3)
		{
			cout << "Enter a schedule name to remove" << endl;
		}else if(option == 4)
		{
			schedule * temp = NULL;
			cout << "Enter a schedule name to edit" << endl;

			cin.get(schedule_name, max_char, '\n');
			cin.ignore(max_char, '\n');

			temp = a_manager.find_schedule(schedule_name);

			if(temp)
			{
				cout << "HHH";
				schedule_edit_option(temp);
			}else
				cout << "Can not find a schedule with this name" << endl;
		}else
			cout << "Quit this system" << endl;
	}while(option < 5);

	if(schedule_name)
	{
		delete [] schedule_name;
	}

	return 0;
}

//schedule_add_option function
void schedule_add_option(schedule_manager & a_manager)
{
	schedule * one_schedule = NULL;
	char * schedule_name = new char[max_char];
	int option = 0;
	cout << "Enter a schedule type to add:" << endl
		<< "#1 - foodcar" << endl
		<< "#2 - library" << endl
		<< "#3 - intership" << endl
		<< "#4 - Quit" << endl;

	cin >> option;
	while(cin.fail())
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Enter a valid number" << endl;
		cin >> option;
	}
	cin.clear();
	cin.ignore(max_char, '\n');

	switch(option)
	{
		case 1:
			one_schedule = new foodcar;
			break;
		case 2:
			one_schedule = new library;
			break;
		case 3:
			one_schedule = new internship;
			break;
		default:
			cout << "Enter an option 1-3" << endl;

	}
	cout << "Enter a schedule name for this new schedule" << endl;
	cin.get(schedule_name, max_char);
	cin.clear();
	cin.ignore(max_char, '\n');

	one_schedule->set_schedule_name(schedule_name);
	one_schedule->set_priority();
	a_manager.add_schedule(one_schedule);
	delete [] schedule_name;
}

//schedule edit option function
void schedule_edit_option(schedule *& a_schedule)
{
	int option = 0;
	char answer = 'n';
	do
	{
		cout << "Select an option" << endl
			<< "#1 - Display all information" << endl
			<< "#2 - Change discription" << endl
			<< "#3 - Change schedule date and time" << endl
			<< "#4 - Change schedule duration" << endl
			<< "#5 - Quit" << endl;

		cin >> option;
		while(cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Enter a valid number" << endl;
			cin >> option;
		}
		cin.clear();
		cin.ignore(100, '\n');

		if(option == 1)
		{
			a_schedule->display();			
		}else if(option == 2)
		{
			a_schedule->set_description();
		}else if(option == 3)
		{
			a_schedule->set_date();
		}else if(option == 4)
		{
			a_schedule->set_duration();
		}else if(option == 5)
		{
			cout << "Do you want to quit" << endl;
			cin >> answer;
			cin.ignore(100, '\n');
		}
	}while(answer != 'y');
}



