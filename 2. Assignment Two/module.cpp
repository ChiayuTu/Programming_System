#include <cstring>
#include "module.h"

//-------------------------------------------------------------------------
//Function for class "schedule"
//Constructor
schedule::schedule()
{
	schedule_name = NULL;

	duration_hour = 0;
	duration_min = 0;

	schedule_day = 0;
	schedule_month = 0;
	schedule_hour = 0;
	schedule_min = 0;

	priority = 0;	
}

//Copy constructor
schedule::schedule(const schedule & obj)
{
	if(obj.schedule_name)
	{
		schedule_name = new char[strlen(obj.schedule_name) + 1];
		strcpy(schedule_name, obj.schedule_name);
	}else
	{
		schedule_name = NULL;
	}

	duration_hour = obj.duration_hour;
	duration_min = obj.duration_min;

	schedule_day = obj.schedule_day;
	schedule_month = obj.schedule_month;
	schedule_hour = obj.schedule_hour;
	schedule_min = obj.schedule_min;

	priority = obj.priority;
}

//Desctructor
schedule::~schedule()
{
	if(schedule_name)
		delete [] schedule_name;
	schedule_name = NULL;
}

//Set the schedule's name
void schedule::set_schedule_name(const char * schedule_name)
{
	//if there is a data in the schedule name, then delete it
	if(this->schedule_name)
	{
		delete [] this->schedule_name;
	}

	this->schedule_name = new char[strlen(schedule_name) + 1];
	strcpy(this->schedule_name, schedule_name);
}

//Set the priority of the schedule
void schedule::set_priority()
{
	cout << "Please, set a new priority of this schedule from 1 to 10:"<< endl;
	int set_num = 0;
	cin >> set_num;

	while(cin.fail())
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Please enter a valid num." << endl;
		cin >> set_num;
	}
	cin.clear();
	cin.ignore(100, '\n');

	if(set_num > 0 && set_num < 11)
	{
		priority = set_num;
		cout << "Set successfully" << endl;
	}else
		cout << "Errer, don't have this option" << endl;
}

//Compare the schedule name
int schedule::compare_schedule_name(schedule * to_compare)
{
	return strcmp(to_compare->schedule_name, schedule_name);
}

int schedule::compare_schedule_name(const char * to_compare)
{	
	if(schedule_name)
		return strcmp(to_compare, schedule_name);
	else
		return 0;
	/*
	   if(schedule_name)
	   {
	   if(strcmp(to_compare, schedule_name) > 0)
	   {
	   return true;
	   }else
	   return false;
	   }else
	   {
	   return false;
	   }
	   */
}

int schedule::compare_priority(schedule * to_compare_schedule)
{
	if(priority == to_compare_schedule->priority)
		return 0;
	else if(priority > to_compare_schedule->priority)
		return 1;
	else 
		return -1;
}

//Display the schedule name
void schedule::display()
{
	if(schedule_name)
		cout << "The schedule name is: " << schedule_name << endl;
	else
		cout << "No schedule name is set." << endl;
}

//Display the priority
void schedule::display_priority()
{
	if(priority)
		cout << "The priority is: " << priority << endl;
	else
		cout << "The priority isn't set." << endl;
}

//Display the durtion
void schedule::display_duration()
{
	if(duration_hour && duration_min)
	{
		cout << "The time is: " << duration_hour << " : " << duration_min << endl;
	}else
	{
		cout << "The duration isn't set." << endl;
	}
}

//Set duration 
void schedule::set_duration()
{
	cout << "Enter durationi: " << endl;
	cout << "Hour: " << endl;
	cin >> duration_hour;

	cout << "Minutes: " << endl;
	cin >> duration_min;

	cout << "Duration set" << endl;
}

//Virtual functions
void schedule::set_description() {}
void schedule::set_date() {}
void schedule::set_location() {}

//-------------------------------------------------------------------------//Function for class "foodcar"
//Constructor
foodcar::foodcar()
{
	street = NULL;
	order = NULL;
}

//Copy constructor
foodcar::foodcar(const foodcar & obj): schedule(obj)
{
	if(obj.street)
	{
		street = new char[strlen(obj.street) + 1];
		strcpy(street, obj.street);
	}else
		street = NULL;

	if(obj.order)
	{
		order = new char[strlen(obj.order) + 1];
		strcpy(order, obj.order);
	}else
		order = NULL;
}

//Desctructor
foodcar::~foodcar()
{
	if(street)
		delete [] street;
	street = NULL;

	if(order)
		delete [] order;
	order = NULL;
}

//Display any information about foodcar
void foodcar::display()
{
	cout << "The foodcar name: " << endl;
	schedule::display();
	cout << endl;

	cout << "The priority num: " << endl;
	schedule::display_priority();
	cout << endl;

	cout << "The duration is:  " << endl;
	schedule::display_duration();
	cout << endl;

	if(order)
	{
		cout << "Your plan to order is: " << order << endl;
	}else
		cout << "You haven't order anything" << endl;

	if(street)
	{
		cout << "The street of foodcar is: " << street << endl;
	}else
		cout << "You haven't add the street" << endl;


	if(schedule_day || schedule_month || schedule_hour || schedule_min)
	{
		cout << "You plan to visit here at: " << endl
			<< schedule_day << "/" << schedule_month << endl
			<< schedule_hour << ":" << schedule_min << endl;
	}else 
		cout << "You aren't a schedule" << endl;

}

//Add description why the user want to go to foodcar
void foodcar::set_description()
{
	if(order)
		delete [] order;

	cout << "What you want to order the food in the foodcar" << endl;

	order = new char[max_char + 1];
	cin.get(order, max_char);
	cin.ignore(max_char, '\n');	
}

//Add the address of the foodcar
void foodcar::set_location()
{
	if(street)
		delete [] street;

	cout << "The foodcar is on which street" << endl;

	street = new char[max_char + 1];
	cin.get(street, max_char);
	cin.ignore(max_char, '\n');	
}

//Set the date when you want to go to the foodcar
void foodcar::set_date()
{
	cout << "Enter the date and the time when you want to go to foodcar" << endl;

	cout << "Month: " << endl;
	cin >> schedule_month;
	cin.ignore(100, '\n');

	cout << "Day  : " << endl;
	cin >> schedule_day;
	cin.ignore(100, '\n');

	cout << "Hour : " << endl;
	cin >> schedule_hour;
	cin.ignore(100, '\n');

	cout << "Min  : " << endl;
	cin >> schedule_min;
	cin.ignore(100, '\n');

	cout << "Set successfully" << endl;
}

//-------------------------------------------------------------------------//Function for class "library"
//Constructor
library::library()
{
	building = NULL;
	topic = NULL;
}

//Copy constructor
library::library(const library & obj): schedule(obj)
{
	if(obj.building)
	{
		building = new char[strlen(obj.building) + 1];
		strcpy(building, obj.building);
	}else
		building = NULL;

	if(obj.topic)
	{
		topic = new char[strlen(obj.topic) + 1];
		strcpy(topic, obj.topic);
	}else
		topic = NULL;
}

//Desctructor
library::~library()
{
	if(building)
		delete [] building;
	building = NULL;

	if(topic)
		delete [] topic;
	topic = NULL;
}

//Display any information about library
void library::display()
{
	cout << "The library name: " << endl;
	schedule::display();
	cout << endl;

	cout << "The priority num: " << endl;
	schedule::display_priority();
	cout << endl;

	cout << "The duration is:  " << endl;
	schedule::display_duration();
	cout << endl;

	if(topic)
	{
		cout << "The topic you plan to study: " << topic << endl;
	}else
		cout << "No topic planned" << endl;

	if(building)
	{
		cout << "The building of the library is: " << building << endl;
	}else
		cout << "You haven't add the building" << endl;


	if(schedule_day || schedule_month || schedule_hour || schedule_min)
	{
		cout << "You plan to go to library at: " << endl
			<< schedule_day << "/" << schedule_month << endl
			<< schedule_hour << ":" << schedule_min << endl;
	}else 
		cout << "You aren't a schedule" << endl;

}

//Add description which topic you want to study in the library
void library::set_description()
{
	if(topic)
		delete [] topic;

	cout << "Which topic you plan to study in the library" << endl;

	topic = new char[max_char + 1];
	cin.get(topic, max_char);
	cin.ignore(max_char, '\n');	
}

//Add the building of the library
void library::set_location()
{
	if(building)
		delete [] building;

	cout << "Where is the building of the library" << endl;

	building = new char[max_char + 1];
	cin.get(building, max_char);
	cin.ignore(max_char, '\n');	
}

//Set the date when you want to go to the library
void library::set_date()
{
	cout << "Enter the date and the time when you want to go to library" << endl;

	cout << "Month: " << endl;
	cin >> schedule_month;
	cin.ignore(100, '\n');

	cout << "Day  : " << endl;
	cin >> schedule_day;
	cin.ignore(100, '\n');

	cout << "Hour : " << endl;
	cin >> schedule_hour;
	cin.ignore(100, '\n');

	cout << "Min  : " << endl;
	cin >> schedule_min;
	cin.ignore(100, '\n');

	cout << "Set successfully" << endl;
}

//-------------------------------------------------------------------------//Function for class "intership"
//Constructor
internship::internship()
{
	company = NULL;
	job = NULL;
}

//Copy constructor
internship::internship(const internship & obj): schedule(obj)
{
	if(obj.company)
	{
		company = new char[strlen(obj.company) + 1];
		strcpy(company, obj.company);
	}else
		company = NULL;

	if(obj.job)
	{
		job = new char[strlen(obj.job) + 1];
		strcpy(job, obj.job);
	}else
		job = NULL;
}

//Desctructor
internship::~internship()
{
	if(company)
		delete [] company;
	company = NULL;

	if(job)
		delete [] job;
	job = NULL;
}


//Display any information about library
void internship::display()
{
	cout << "The intership name: " << endl;
	schedule::display();
	cout << endl;

	cout << "The priority num: " << endl;
	schedule::display_priority();
	cout << endl;

	cout << "The duration is:  " << endl;
	schedule::display_duration();
	cout << endl;

	if(job)
	{
		cout << "What job you will do: " << job << endl;
	}else
		cout << "No job planned" << endl;

	if(company)
	{
		cout << "What company you do your intership: " << company << endl;
	}else
		cout << "You haven't add a company" << endl;


	if(schedule_day || schedule_month || schedule_hour || schedule_min)
	{
		cout << "You plan to go to intership at: " << endl
			<< schedule_day << "/" << schedule_month << endl
			<< schedule_hour << ":" << schedule_min << endl;
	}else 
		cout << "You aren't a schedule" << endl;

}

//Add description which job you will find
void internship::set_description()
{
	if(job)
		delete [] job;

	cout << "What the job you will do" << endl;

	job = new char[max_char + 1];
	cin.get(job, max_char);
	cin.ignore(max_char, '\n');	
}

//Add a company you will do your intership
void internship::set_location()
{
	if(company)
		delete [] company;

	cout << "What company you will do your intership" << endl;

	company = new char[max_char + 1];
	cin.get(company, max_char);
	cin.ignore(max_char, '\n');	
}

//Set the date when you want to go to the intership
void internship::set_date()
{
	cout << "Enter the date and the time when you want to go to intership" << endl;

	cout << "Month: " << endl;
	cin >> schedule_month;
	cin.ignore(100, '\n');

	cout << "Day  : " << endl;
	cin >> schedule_day;
	cin.ignore(100, '\n');

	cout << "Hour : " << endl;
	cin >> schedule_hour;
	cin.ignore(100, '\n');

	cout << "Min  : " << endl;
	cin >> schedule_min;
	cin.ignore(100, '\n');

	cout << "Set successfully" << endl;
}
































