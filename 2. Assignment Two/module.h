#include <iostream>
#include <cstring>

using namespace std;

const int array_size = 300;
const int max_char = 300;

//Schedule class is a base class
class schedule
{
	public:
		//Constructor
		schedule();
		//Copy constructor
		schedule(const schedule & obj);
		//Desctructor
		~schedule();
		
		//Set the schedule name
		void set_schedule_name(const char * schedule_name);
		//Set the schedule priority
		void set_priority(); 

		//Compare the schedule name
		int compare_schedule_name(schedule * to_compare);
		int compare_schedule_name(const char * to_compare);
		//compare the schedule priority
		int compare_priority(schedule * to_compare_schedule);

		//Display priority and duration
		void display_priority();
		void display_duration();
		void set_duration();

		//virtual function because in the derived classes will
		//will have those functions
		virtual void display();
		virtual void set_description();
		virtual void set_date();
		virtual void set_location();

	protected:
		int duration_hour;
		int duration_min;
		int schedule_day;
		int schedule_month;
		int schedule_hour;
		int schedule_min;

		char * schedule_name;

		int priority;
};

//Class foodcar is derived class from the base class
//They have "is a" relationship
class foodcar: public schedule
{
	public:
		//Constructor
		foodcar();
		//Destructor
		~foodcar();
		//Copy constructor
		foodcar(const foodcar & obj);
		
		//Display any indormation about foodcar
		void display();
		//Add description about foodcar
		void set_description();
		//Add the date 
		void set_date();
		//Add location
		void set_location();

	private:
		char * street;
		char * order;
};

//Class library is derived class from the base class
//They have "is a" relationship
class library: public schedule
{
	public:
		//Constructor
		library();
		//Destructor
		~library();
		//Copy constructor
		library(const library & obj);

		void display();
		void set_description();
		void set_date();
		void set_location();

	private:
		char * building;
		char * topic;

};

//Class intership is derived class from the base class
//They have "is a" relationship
class internship: public schedule
{
	public:
		//Constructor
		internship();
		//Destructor
		~internship();
		//Copy constructor
		internship(const internship & obj);

		void display();
		void set_description();
		void set_date();
		void set_location();

	private:
		char * company;
		char * job;
};

//Node class
class node
{
	public:
		node();
		~node();
		node(const node * obj);
		void constructor_helper(int i);
		
		node *& go_next();
		node *& go_prev();
		void connect_next(node * connection);
		void connect_prev(node * connection);
		void copy_schedule(schedule ** schedule_list, int schedule_size, int i);
		void delete_list(int i);
		void display();
		void display(int i);
		int compare_priority(schedule * a_schedule);
		void add_schedule(schedule *& a_schedule);
		int add_schedule_helper(schedule *& a_schedule, int i);
		int add_schedule_helper(const char * schedule_name, int i);
		void shift_x(int i, int j);
		void shift_y(int i);
		bool remove_schedule(const char * schedule_name);
		bool find_schedule(const char * schedule_name, schedule *& a_schedule);

	protected:
		node * next;
		node * prev;

		int list_size;
		schedule ** list;
};

class schedule_manager
{
	public:
		schedule_manager();
		~schedule_manager();
		schedule_manager(const schedule_manager & obj);

		void copy_nodes(node* source, node *& hold);

		void add_schedule(schedule *& a_schedule);
		void remove_schedule(const char * schedule_name);
		void delete_list(node *& head);
		void display();
		void display_highest_priority();
		schedule * find_schedule(const char * schedule_name);

	protected:
		node * head;
		node * tail;
		
		void add_schedule(node *& head, schedule *& a_schedule);
		void remove_schedule(node * head, const char * schedule_name);
		void display(node * head);
		schedule * find_schedule(node * head, const char * schedule_name);

};

































