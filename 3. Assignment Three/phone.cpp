#include "phone.h"

device_info::device_info()
{
	phone_num = 0;	
}

device_info::device_info(const device_info & obj)
{
	name = obj.name;	

	phone_num = obj.phone_num;
}

device_info::~device_info()
{
	phone_num = 0;
}

void device_info::set_name()
{
	cout << "Set the name of your device" << endl;
	cin >> name;
	cin.ignore(100, '\n');

	cout << "Set successfully" << endl;
	cout << "set_name() from phone.cpp" << endl;
}

void device_info::set_num()
{
	cout << "Enter a new device number" << endl;
	cin >> phone_num;

	while(cin.fail())
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Please enter valid priority.";
		cin >> phone_num;
	}
	cin.clear();
	cin.ignore();

	cout << "Phone num is set" << endl;
	cout << "set_num() from phone.cpp" << endl;
}

ostream & operator << (ostream & out, const device_info & to_display)
{
	to_display.display(out);
	return out;
}

bool device_info::operator > (const device_info & to_compare)
{
	if(name > to_compare.name) 
		return true;
	else
		return false;	
}

bool device_info::operator < (const device_info & to_compare)
{
	if(name < to_compare.name) 
		return true;
	else
		return false;	
}

bool device_info::operator <= (const device_info & to_compare)
{
	if(name <= to_compare.name) 
		return true;
	else
		return false;	
}

bool device_info::operator >= (const device_info & to_compare)
{
	if(name >= to_compare.name) 
		return true;
	else
		return false;	
}

bool device_info::operator == (const device_info & to_compare)
{
	if(name == to_compare.name) 
		return true;
	else
		return false;	
}

bool device_info::operator == (int to_compare)
{
	if(phone_num == to_compare) 
		return true;
	else
		return false;	
}

bool device_info::operator != (const device_info & to_compare)
{
	if(name != to_compare.name) 
		return true;
	else
		return false;	
}

device_info & device_info::operator = (const device_info & to_copy)
{
	if(this == &to_copy)
		return *this;

	name = to_copy.name;

	return *this;
}

bool device_info::operator > (const string_data & to_compare)
{
	if(name > to_compare)
		return true;
	else
		return false;
}

bool device_info::operator < (const string_data & to_compare)
{
	if(name < to_compare)
		return true;
	else
		return false;
}

bool device_info::operator >= (const string_data & to_compare)
{
	if(name >= to_compare)
		return true;
	else
		return false;
}

bool device_info::operator <= (const string_data & to_compare)
{
	if(name <= to_compare)
		return true;
	else
		return false;
}

bool device_info::operator == (const string_data & to_compare)
{
	if(name == to_compare)
		return true;
	else
		return false;
}

bool device_info::operator != (const string_data & to_compare)
{
	if(name != to_compare)
		return true;
	else
		return false;
}

void device_info::read(istream & in)
{
	in >> name;
	in.ignore(100, '\n');
	in >> phone_num;
	in.ignore(100, '\n');
}

void device_info::write(ostream & out)
{
	out << name << endl;
	out << phone_num << endl;
}

void device_info::display(ostream & out)const
{
	out << "phone's name" << name << endl;
	out << "phone's num " << phone_num << endl;
}

void device_info::set_description() {}

//----------------------------------------------------------------------------------------------------------------------
node::node()
{
	left = NULL;
	right = NULL;
}

node::node(const node & a_node): device_info(a_node), left(0), right(0) {}

node::node(device_info * a_info): device_info(*a_info), left(0), right(0) {}

node::~node()
{	
	left = NULL;
	right = NULL;
}

void node::connect_right(node * connection) 
{	
	right = connection;
}

void node::connect_left(node * connection) 
{	
	left = connection;
}

node *& node::go_right() 
{
	return right;
}

node *& node::go_left() 
{
	return left;
}

node & node::operator = (const node & to_copy)
{
	if (this == &to_copy)
		return *this;

	this->device_info::operator = (to_copy);
	return *this;
}

bool node::operator != (const node & to_compare) {

	if (this->device_info::operator != (to_compare)) 
		return true;
	else
		return false;
}

bool node::operator == (const node & to_compare) 
{
	if (this->device_info::operator == (to_compare)) 
		return true;
	else
		return false;
}

bool node::operator == (int to_compare) 
{
	if (this->device_info::operator == (to_compare))
		return true;
	else
		return false;
}

ostream& operator << (ostream& out, const node & to_display) 
{
	to_display.display(out);
	return out;
}

void node::display(ostream & out) const 
{
	device_info::display(out);
}

void node::set_description() {}

void node::read(istream & in) 
{
	device_info::read(in);
}

void node::write(ostream & out) 
{
	device_info::write(out);
}

//----------------------------------------------------------------------------------------------------------------------
land_line::land_line()
{
	land_line_price = 0;
}

land_line::land_line(const land_line & obj):node(obj)
{
	land_line_desc = obj.land_line_desc;
	land_line_plan = obj.land_line_plan;

	land_line_price = obj.land_line_price;
}

land_line::~land_line()
{
	land_line_price = 0;
}

void land_line::set_description()
{
	cout << "The description of land line phone" << endl;
	cin >> land_line_desc;
	cin.ignore(100, '\n');

	cout << "The description is set" << endl;
	cout << "from land_line_desc" << endl;
}

void land_line::set_network_plan()
{
	cout << "What is your land line price" << endl;
	cin >> land_line_plan;
	cin.ignore(100, '\n');

	cout << "The plan is set" << endl;
	cout << "from set_network_plan" << endl;
}

void land_line::set_land_line_price()
{
	cout << "How much is your network price" << endl;
	cin >> land_line_price;

	cout << "The price is set" << endl;
	cout << "from set_land_line_price" << endl;
}

ostream & operator << (ostream & out, const land_line & to_display)
{
	to_display.display(out);

	return out;
}

void land_line::display(ostream & out) const
{
	node :: display(out);

	out << "Description  : " << land_line_desc << endl;
	out << "Network plan : " << land_line_plan << endl;
	out << "Network price: " << land_line_price << endl;
}

land_line & land_line::operator = (const land_line & to_copy)
{
	if(this == &to_copy)
		return *this;

	this->node::operator = (to_copy);
	land_line_desc = to_copy.land_line_desc;
	land_line_plan = to_copy.land_line_plan;
	land_line_price = to_copy.land_line_price;

	return *this;
}

void land_line::read(istream & in)
{
	node::read(in);

	in >> land_line_desc;
	in.ignore(100, '\n');
	in >> land_line_plan;
	in.ignore(100, '\n');
	in >> land_line_price;
	in.ignore(100, '\n');
}

void land_line::write(ostream & out)
{
	node::write(out);

	out << land_line_desc << endl;
	out << land_line_plan << endl;
	out << land_line_price << endl;
}

//----------------------------------------------------------------------------------------------------------------------
satellite::satellite()
{
	satellite_price = 0;
}

satellite::satellite(const satellite & obj):node(obj)
{
	satellite_desc = obj.satellite_desc;
	satellite_company = obj.satellite_company;

	satellite_price = obj.satellite_price;
}

satellite::~satellite()
{
	satellite_price = 0;
}

void satellite::set_description()
{
	cout << "The description of satellite phone" << endl;
	cin >> satellite_desc;
	cin.ignore(100, '\n');

	cout << "The description is set" << endl;
	cout << "from set_description()" << endl;
}

void satellite::set_satellite_company()
{
	cout << "What satellite company you selected" << endl;
	cin >> satellite_company;
	cin.ignore(100, '\n');

	cout << "The satellite is set" << endl;
	cout << "from set_satellite_company()" << endl;
}

void satellite::set_satellite_price()
{
	cout << "What is the price of your satellite phone plan" << endl;
	cin >> satellite_price;
	cin.ignore(100, '\n');

	cout << "The satellite price is set" << endl;
	cout << "from set_satellite_price()" << endl;
}

ostream & operator << (ostream & out, const satellite & to_display)
{
	to_display.display(out);

	return out;
}

satellite & satellite::operator = (const satellite & to_copy)
{
	if(this == &to_copy)
		return *this;

	this->node::operator = (to_copy);
	satellite_desc = to_copy.satellite_desc;
	satellite_company = to_copy.satellite_company;
	satellite_price = to_copy.satellite_price;

	return *this;
}

void satellite::display(ostream & out) const
{
	node::display(out);

	out << "Description:       " << satellite_desc << endl;
	out << "Satellite company: " << satellite_company << endl;
	out << "Plan price:        " << satellite_price << endl;
}

void satellite::read(istream & in)
{
	node::read(in);

	in >> satellite_desc;
	in.ignore(100, '\n');
	in >> satellite_company;
	in.ignore(100, '\n');
	in >> satellite_price;
	in.ignore(100, '\n');
}

void satellite::write(ostream & out)
{
	node::write(out);

	out << satellite_desc << endl;
	out << satellite_company << endl;
	out << satellite_price << endl;
}


//----------------------------------------------------------------------------------------------------------------------

cellphone::cellphone()
{
	year = 0;
	month = 0;
	day = 0;
}

cellphone::cellphone(const cellphone & obj):node(obj)
{
	cellphone_desc = obj.cellphone_desc;
	data_plan = obj.data_plan;

	year = obj.year;
	month = obj.month;
	day = obj.day;
}

cellphone::~cellphone()
{
	year = month = day = 0;
}

void cellphone::set_description()
{
	cout << "The description of your cellphone" << endl;
	cin >> cellphone_desc;
	cin.ignore(100, '\n');

	cout << "The description is set" << endl;
	cout << "from set_description()" << endl;
}

void cellphone::set_data_plan()
{
	cout << "What is your data plan" << endl;
	cin >> data_plan;
	cin.ignore(100, '\n');

	cout << "The data plan is set" << endl;
	cout << "from set_data_plan()" << endl;
}

void cellphone::set_duration()
{
	cout << "When you start your data plan" << endl;
	cout << "year" << endl;
	cin >> year;

	cout << "month" << endl;
	cin >> month;

	cout << "day" << endl;
	cin >> day;

	cout << "The plan will start at: " << year << "/" << month << "/" << day << endl;
}

ostream & operator << (ostream & out, const cellphone & to_display)
{
	to_display.display(out);

	return out;
}

cellphone & cellphone::operator = (const cellphone & to_copy)
{
	if(this == &*this)
		return *this;

	this->node::operator = (to_copy);
	cellphone_desc = to_copy.cellphone_desc;
	data_plan = to_copy.data_plan;
	year = to_copy.year;
	month = to_copy.month;
	day = to_copy.day;

	return *this;
}

void cellphone::display(ostream & out) const
{
	node::display(out);
	out << "Description: " << cellphone_desc << endl;
	out << "Data plan:   " << data_plan << endl;
	out << "Plan start:  " << year << "/" << month << "/" << day << endl;	
}

void cellphone::read(istream & in)
{
	node::read(in);

	in >> cellphone_desc;
	in.ignore(100, '\n');
	in >> data_plan;
	in.ignore(100, '\n');
	in >> year;
	in.ignore(100, '\n');
	in >> month;
	in.ignore(100, '\n');
	in >> day;
	in.ignore(100, '\n');
}

void cellphone::write(ostream & out)
{
	node::write(out);

	out << cellphone_desc << endl;
	out << data_plan << endl;
	out << year << endl;
	out << month << endl;
	out << day << endl;
}

//----------------------------------------------------------------------------------------------------------------------
tree_manager::tree_manager()
{
	root = NULL;
}

tree_manager::tree_manager(const tree_manager & obj)
{
	root = NULL;
	copy_tree(root, obj.root);
}

tree_manager & tree_manager::operator = (const tree_manager & src) 
{
	if (this == &src) {
		return *this;
	}

	root = NULL;

	copy_tree(root, src.root);

	return *this;
}

void tree_manager::copy_tree(node *& dest, node * src) 
{
	if (src) 
	{
		dest = new node(*src);
		copy_tree(dest->go_left(), src->go_left());
		copy_tree(dest->go_right(), src->go_right());
	}
}

tree_manager::~tree_manager() 
{
	if (root) 
	{
		delete_all(root);
	}
}

void tree_manager::delete_all(node *& root) 
{
	if (root)
	{	
		delete_all(root->go_right());
		delete_all(root->go_left());
		delete root;
		root = NULL;
	} 
}

ostream & operator << (ostream& out, tree_manager & to_display) 
{
	if (!to_display.root) 
	{	
		out << "Nothing to display. " << endl;
	} else
		to_display.display_tree(out, to_display.root);

	return out;
}

void tree_manager::display_tree(ostream & out, node * root) 
{
	if (root != NULL) {
		display_tree(out, root->go_left());
		out << *root;
		out << endl;
		display_tree(out, root->go_right());
	}
}

void tree_manager::add_info(node*& to_add) 
{
	add_info(root, to_add);
}

void tree_manager::add_info(node *& root, node *& to_add)
{
	if(root) 
	{
		if(*root < *to_add) 
		{
			add_info(root->go_right(), to_add);
		}else if (*root > *to_add) 
		{
			add_info(root->go_left(), to_add);
		}
	}else
		root = to_add;
}

tree_manager & tree_manager::operator += (node*& to_add) 
{
	add_info(root, to_add);
	return *this;
}

device_info* tree_manager::retrieve_info(const string_data & to_retrieve)
{
	if(!root)
		return 0;
	return retrieve_info(root, to_retrieve);
}

device_info* tree_manager::retrieve_info(node *& root, const string_data & to_retrieve)
{
	if(root) 
	{
		if(*root > to_retrieve) 
		{
			return retrieve_info(root->go_left(), to_retrieve);
		}else if (*root < to_retrieve) 
		{
			return retrieve_info(root->go_right(), to_retrieve);
		}else 
		{
			return root;
		}

	}else
		return NULL;
}

node *& tree_manager::min_of_right_tree(node *& root)
{
	if(root && root->go_left() != NULL) 
	{
		return min_of_right_tree(root->go_left());
	}else
		return root;
}

void tree_manager::remove_info(const string_data & to_remove)
{
	remove_info(root, to_remove);
}

void tree_manager::remove_info(node *& root, const string_data & to_remove)
{
	if(root) 
	{
		if(*root < to_remove)
		{
			remove_info(root->go_right(), to_remove);
		}else if(*root > to_remove) 
		{
			remove_info(root->go_left(), to_remove);
		}else{
			if(!root->go_right() && !root->go_left()) 
			{
				delete root;
				cout << "Device removed successfully." << endl;
				root = NULL;
			}else if(root->go_right() && !root->go_left()) 
			{
				node* temp = root->go_right();
				delete root;
				cout << "Device removed successfully." << endl;
				root = temp;
			}else if(!root->go_right() && root->go_left()) 
			{

				node* temp = root->go_left();
				delete root;
				cout << "Device removed successfully." << endl;
				root = temp;
			}else if(root->go_right() && root->go_left()) 
			{
				node * to_swap = min_of_right_tree(root->go_right());
				node * temp = to_swap;
				*to_swap = *root;
				*root = *temp;
				remove_info(root->go_right(), to_remove);
			}

		}
	}else
		cout << "Nothing to delete with that title." << endl;

}

void tree_manager::read(istream & in) 
{
	string_data input;
	in >> input;
	in.ignore(100, '\n');

	node * to_add = NULL;

	if(input == "L") 
	{
		to_add = new land_line;
	}else if (input == "S")
	{
		to_add = new satellite;
	}else if (input == "C") 
	{
		to_add = new cellphone;
	}

	if(to_add) 
	{
		to_add->read(in);
		add_info(to_add);
	}
}

void tree_manager::write(ostream & out) 
{
	write(root, out);
}

void tree_manager::write(node *& root, ostream & out)
{
	if(root)
	{
		land_line * to_save = NULL;
		to_save = dynamic_cast < land_line* > (root);
		if(to_save) 
		{
			out << "L" << endl;
		} else 
		{
			satellite * to_save2 = NULL;
			to_save2 = dynamic_cast < satellite* > (root);
			if(to_save2) 
			{
				out << "S" << endl;
			}else
			{
				cellphone * to_save3 = NULL;
				to_save3 = dynamic_cast <cellphone*> (root);
				if (to_save3) 
				{
					out << "C" << endl;
				}
			}
		}

		root->write(out);
		write(root->go_left(), out);
		write(root->go_right(), out);
	}

}

























