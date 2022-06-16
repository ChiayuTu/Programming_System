#include <cstring>
#include <iostream>
#include <fstream>

using namespace std;

const int size = 200;

class string_data
{
	public:
		string_data();
		string_data(const string_data & obj);
		~string_data();

		friend ostream & operator << (ostream & out, const string_data & to_display);
		friend istream & operator >> (istream & in, string_data & to_input);

		bool operator != (const string_data & to_compare);
		bool operator == (const string_data & to_compare);
		bool operator == (const char * to_compare);
		bool operator <= (const string_data & to_compare);
		bool operator >= (const string_data & to_compare);
		bool operator < (const string_data & to_compare);
		bool operator > (const string_data & to_compare);

		string_data & operator = (const string_data & obj);

	private:
		char * str;
};

class device_info
{
	public:
		device_info();
		device_info(const device_info & obj);
		~device_info();
		void set_name();
		void set_num();

		virtual void display(ostream & out)const;
		virtual void write(ostream & out);
		virtual void read(istream & in);
		virtual void set_description();

		friend ostream & operator << (ostream & out, const device_info & to_display);

		bool operator > (const device_info & to_compare);
		bool operator < (const device_info & to_compare);
		bool operator <= (const device_info & to_compare);
		bool operator >= (const device_info & to_compare);
		bool operator == (const device_info & to_compare);
		bool operator == (int to_compare);
		bool operator !=(const device_info & to_compare);

		bool operator > (const string_data & to_compare);
		bool operator < (const string_data & to_compare);
		bool operator <= (const string_data & to_compare);
		bool operator >= (const string_data & to_compare);
		bool operator == (const string_data & to_compare);
		bool operator != (const string_data & to_compare);

		device_info & operator = (const device_info & to_copy);

	private:	
		string_data name;
		int phone_num;
};

class node : public device_info
{
	public:
		node();
		~node();
		node(const node & a_node);	
		node(device_info * a_info);

		node *& go_left();
		node *& go_right();
		node & operator = (const node & to_copy);
		void connect_left(node * connection);
		void connect_right(node * connection);

		friend ostream & operator << (ostream & out, const node & to_display);
		bool  operator == (const node & to_compare);
		bool  operator != (const node & to_compare);
		bool  operator == (int to_compare);

		virtual void set_description();
		virtual void display(ostream & out)const;
		virtual void write(ostream & out);
		virtual void read(istream & in);

	private:
		node * left;
		node * right;
}; 

class land_line : public node
{
	public:
		land_line();
		land_line(const land_line & obj);
		~land_line();

		void set_description();
		void set_land_line_price();
		void set_network_plan();
		void display(ostream & out) const;
		void write(ostream & out);
		void read(istream & in);

		friend ostream & operator << (ostream & out, const land_line & to_display);

		land_line & operator = (const land_line & to_copy);

	private:
		string_data land_line_desc;
		string_data land_line_plan;

		int land_line_price;
};

class satellite : public node
{
	public:
		satellite();
		satellite(const satellite & obj);
		~satellite();

		void set_description();
		void set_satellite_company();
		void set_satellite_price();	
		void display(ostream & out) const;
		void write(ostream & out);
		void read(istream & in);

		friend ostream & operator << (ostream & out, const satellite & to_display);

		satellite & operator = (const satellite & to_copy);

	private:
		string_data satellite_desc;
		string_data satellite_company;

		int satellite_price;
};

class cellphone : public node
{
	public:
		cellphone();
		cellphone(const cellphone & obj);
		~cellphone();

		void set_description();
		void set_data_plan();
		void set_duration();	
		void display(ostream & out) const;
		void write(ostream & out);
		void read(istream & in);

		friend ostream & operator << (ostream & out, const cellphone & to_display);

		cellphone & operator = (const cellphone & to_copy);

	private:
		string_data cellphone_desc;
		string_data data_plan;

		int year;
		int month;
		int day;
};

class tree_manager
{
	public:
		tree_manager();
		tree_manager(const tree_manager & obj);
		~tree_manager();

		friend ostream & operator << (ostream& out, tree_manager & to_display);
		tree_manager & operator = (const tree_manager & src);
		tree_manager & operator += (node*& to_add);

		device_info * retrieve_info(const string_data & to_retrieve);
		void remove_info(const string_data & to_remove);
		void add_info(node*& to_add);
		void read(istream & in);
		void write(ostream & out);

	private:
		node * root;

		node *& min_of_right_tree(node *& root);
		device_info * retrieve_info(node *& root, const string_data & to_retrieve);
		void add_info(node *& root, node *& to_add);
		void remove_info(node *& root, const string_data & to_remove);
		void display_tree(ostream & out, node * root);
		void copy_tree(node *& dest, node * src);
		void delete_all(node *& root);
		void write(node *& root, ostream & out);

};


