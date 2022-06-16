#include "module.h"

//-------------------------------------------------------------------------//Function for class "node"
//
node::node()
{
	next = NULL;
	prev = NULL;

	list_size = 0;

	list = new schedule * [array_size];
	/*
	for(int i = 0; i < array_size; i++)
	{
		if(i < array_size)
		{
			list[i] = NULL;
		}
	}
	*/
	constructor_helper(0);
}

void node::constructor_helper(int i)
{
	if(i < array_size)
	{
		list[i] = NULL;
		constructor_helper(i + 1);
	}
}

node::node(const node * obj )
{
	next = NULL;
	prev = NULL;

	list_size = 0;

	copy_schedule(obj->list, obj->list_size, 0);
}

//
void node::copy_schedule(schedule ** schedule_list, int schedule_size, int i)
{
	if(i < schedule_size)
	{
		list[i] = new schedule(*schedule_list[i]);
		copy_schedule(schedule_list, schedule_size, i + 1);
	}else
		list_size = schedule_size;
}

//
node::~node()
{
	next = NULL;
	prev = NULL;

	/*
	   for(int i = 0; i < list_size; i++)
	   {
	   if(i < list_size)
	   {
	   i = i + 1;
	   delete list[i];
	   }else
	   {
	   list_size = 0;
	   }
	   }
	   */
	delete_list(0);
	delete [] list;
}

//
void node::delete_list(int i)
{
	if(i < list_size)
	{
		delete_list(i + 1);
		delete list[i];
	}else
	{
		list_size = 0;
	}
}

//go next function and return the next pointer in the list
node *& node::go_next()
{
	return next;
}

//go previous function and return the previous pointer in the list
node *& node::go_prev()
{
	return prev;
}

//connect to the next pointer
void node::connect_next(node * connection)
{
	next = connection;
}

//connect to the previous pointer
void node::connect_prev(node * connection)
{
	prev = connection;
}

//display all the data associated with a schedule
void node::display()
{
	/*
	if(list_size)
	{
		for(int i = 0; i < list_size; i++)
		{
			list[i]->display();
			i = i + 1;
		}
	}else
		cout << "Nothing to display" << endl;
	*/
	if(list_size)
	{
		display(0);
	}else
		cout << "Nothing can display" << endl;
}

void node::display(int i)
{
	if(i < list_size)
	{
		list[i]->display();
		display(i + 1);
	}
}

//
int node::compare_priority(schedule * a_schedule)
{
	return list[0]->compare_priority(a_schedule);
}

//Add a schedule in the list
void node::add_schedule(schedule *& a_schedule)
{
	if(list_size != 0)
	{
		int num = add_schedule_helper(a_schedule, 0);

		if(num == -1)
		{
			cout << "Too many schedules with this priority" << endl;
		}else
		{
			shift_x(num, list_size);
			list[num] = a_schedule;
			list_size++;
		}
	}else
	{
		list[0] = a_schedule;
		list_size++;
	}
}

//
int node::add_schedule_helper(schedule *& a_schedule, int i)
{
	if(list[i] == NULL)
	{
		return i;
	}else if(i < array_size)
	{
		int num = list[i]->compare_schedule_name(a_schedule);

		if(num <= 0)
		{
			return add_schedule_helper(a_schedule, i + 1);
		}else
		{
			return i;
		}
	}else
	{
		return -1;
	}
}

//
int node::add_schedule_helper(const char * schedule_name, int i)
{
	if(i < array_size)
	{
		if(!list[i])
		{
			return -1;
		}

		int num = list[i]->compare_schedule_name(schedule_name);

		if(num != 0)
		{
			return add_schedule_helper(schedule_name, i + 1);
		}else
		{
			return i;
		}
	}else
		return 0;

}

//
void node::shift_x(int i, int j)
{
	if(j > i)
	{
		list[j] = list[j - 1];
		shift_x(i, j - 1);
	}
}

//
void node::shift_y(int i)
{
	if(i < list_size)
	{
		list[i] = list[i + 1];
		shift_y(i + 1);
	}
}

//Remove a schedule from the list
bool node::remove_schedule(const char * schedule_name)
{
	if(!list_size)
	{
		cout << "There are no any schedule" << endl;
		return false;
	}else
	{
		int i = add_schedule_helper(schedule_name, 0);

		if(i == -1)
		{
			cout << "No any schedule for this schedule name" << endl;
			return false;
		}else
		{
			delete list[i];
			shift_y(i);
			list_size--;
			return true;
		}
	}

	return false;
}

//Find a schedule in the list
bool node::find_schedule(const char * schedule_name, schedule *& a_schedule)
{
	int index = add_schedule_helper(schedule_name, 0);

	if(index == -1)
	{
		return false;
	}else
	{
		a_schedule = list[index];
		return true;
	}
}

//------------------------------------------------------------------------
//Function for class "schedule_manager"
//
schedule_manager::schedule_manager()
{
	head = NULL;
	tail = NULL;
}

//
schedule_manager::~schedule_manager()
{
	delete_list(head);
}

//
schedule_manager::schedule_manager(const schedule_manager & obj)
{
	head = NULL;
	tail = NULL;

	copy_nodes(obj.head, head);
}

//copy constructor to copy from source head to hold head
void schedule_manager::copy_nodes(node * source, node *& hold)
{
	if(!source)
	{
		node * temp = new node(*hold);
		hold->connect_next(temp);
		copy_nodes(source->go_next(), hold->go_next());
		hold->go_next()->connect_prev(hold);
	}else
	{
		tail = hold->go_prev();
	}
}

//Add a schedule
void schedule_manager::add_schedule(schedule *& a_schedule)
{
	add_schedule(head, a_schedule);
}

//recursive add function
void schedule_manager::add_schedule(node *& head, schedule *& a_schedule)
{
	if(head != NULL)
	{
		int num = head->compare_priority(a_schedule);
		if(num < 0)
		{
			add_schedule(head->go_next(), a_schedule);
		}else if(num == 0)
		{
			head->add_schedule(a_schedule);
		}else
		{
			node * temp = new node;
			temp->connect_next(head);
			if(head->go_prev())
			{
				temp->connect_prev(head->go_prev());
				temp->go_prev()->connect_next(temp);
			}
			head->connect_prev(temp);
			temp->add_schedule(a_schedule);
			head = temp;
		}
	}else
	{
		head = new node;
		head->add_schedule(a_schedule);
	}

	cout << "Successfully add" << endl;
}

//Display function
void schedule_manager::display()
{
	if(!head)
	{
		cout << "No schedule can display in the list" << endl;
	}else
	{
		display(head);
	}
}

//Recursive display function
void schedule_manager::display(node * head)
{
	if(head)
	{
		head->display();
		display(head->go_next());
	}
}

//find schedule function
schedule * schedule_manager::find_schedule(const char * schedule_name)
{
	if(!head) return 0;
	return find_schedule(head, schedule_name);
}

//recursive function
schedule * schedule_manager::find_schedule(node * head, const char * schedule_name)
{
	if(head)
	{
		schedule * a_schedule = NULL;

		bool num = head->find_schedule(schedule_name, a_schedule);
		if(num)
		{
			return a_schedule;
		}else
			return find_schedule(head->go_next(), schedule_name);
	}else
	{
		return NULL;
	}
}

//Remove function
void schedule_manager::delete_list(node *& head)
{
	if(head)
	{
		delete_list(head->go_next());
		delete head;
	}else
	{
		head = NULL;
		tail = NULL;
	}
}

void schedule_manager::remove_schedule(const char * schedule_name)
{
	remove_schedule(head, schedule_name);
}

void schedule_manager::remove_schedule(node * head, const char * schedule_name)
{
	if(head)
	{
		if(head->remove_schedule(schedule_name))
		{
			cout << "The schedule is removed" << endl;
		}else
		{
			remove_schedule(head->go_next(), schedule_name);
		}
	}else
		cout << "No schedule is in the list" << endl;
}
