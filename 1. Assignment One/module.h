//module
#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

//Max char*
const int MAX_CHAR = 500;
const int MAX_SIZE = 3;

class Module
{
	public:
		//default constructor, destructor, and copy constructor
		//Class Module has a dynamic memory(char * product_name)
		Module();
		
		//Destructor to delete product_name char memory
		~Module();

		//copies a product name
		Module(const Module & obj);

		//Change the name for the two derived classes
		void change_name(const char * new_name);

		//Compare the product name
		bool compare_name(const char * to_compare);

		//Display the the product name
		void display();

	protected:
		//Protected data member product_title that will be used
		//by display and change title function above 
		char * product_name;
};

class ScheduleProduct: public Module
{
	public:
		ScheduleProduct();
		~ScheduleProduct();
		ScheduleProduct(const ScheduleProduct & obj);
		void change_priority();
		void change_description();
		void display();

	private:
		int priority;
		char * description;
};

class Product: public Module
{
	public:
		Product();
		Product(const Product & obj);
		~Product();
		void display();
		void change_delivery();

	protected:
		char * delivery;
};

class Node: public Product
{
	public:
		Node();
		~Node();
		Node(const Product & obj);
		Node *& go_next();
		void connect_next(Node * connection);

	protected:
		Node * next;
};

class ProductManage
{
	public:
		ProductManage();
		~ProductManage();
		ProductManage(const ProductManage & obj);
		void display_NationDistribution();
		void display_LocalDistribution();
		bool add_NationDistribution(const Product & a_product);
		bool add_LocalDistribution(const Product & a_product);
		bool change_NationDistribution(char * searched_name);
		bool change_LocalDistribution(char * searched_name);
	
	protected:
		Node** table;
		Node *& add_product(Node *& head);
		void delete_all(Node *& head);
		void copy(Node *& newhead, Node * oldhead);
		void display(Node * head);
		Node *& search_name(Node *& head, char * searched_name);
};

