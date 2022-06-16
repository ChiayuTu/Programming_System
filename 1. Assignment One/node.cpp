#include <iostream>
#include <cstring>
#include "module.h"

using namespace std;

//Product class functions
//----------------------------------------------------------------	
//Constructor
Product::Product()
{
	delivery = NULL;
}

//copies constructor
Product::Product(const Product & obj): Module(obj)
{
	if(obj.delivery)
	{
		delivery = new char[strlen(obj.delivery) + 1];
		strcpy(delivery, obj.delivery);
	}else
		delivery = NULL;
}

//Desctructor
Product::~Product()
{
	if(delivery)
		delete [] delivery;
	delivery = NULL;
}

//Change the delivery for this product
void Product::change_delivery()
{
	if(cin)
	{
		cin.clear();
		cin.ignore(MAX_SIZE, '\n');
	}

	cout << "Enter how to delivery: " << endl;

	if(delivery)
		delete [] delivery;

	delivery = new char[MAX_CHAR];
	cin.get(delivery, MAX_CHAR);
	cin.ignore(MAX_CHAR, '\n');
}

//Display
void Product::display()
{
	cout << "The product name is: ";
       	Module::display();
        cout << endl;

	cout << "The delivery way is: ";
	cout << endl;
	if(delivery)
	{
		cout << delivery << endl;
	}else
	{
		cout << "Not set the way of delivery" << endl;
	}

}

//Product class functions
//----------------------------------------------------------------	
//initialize next pointer to NULL
Node::Node()
{
	next = NULL;
}

//copies constructor
Node::Node(const Product & obj): Product(obj)
{
	next = NULL;
}

//Destructor
Node::~Node()
{
	next = NULL;
}

//Function that returns the next value of the list instead of using a next pointer
Node *& Node:: go_next()
{
	return next;
}

//connect nodes
void Node::connect_next(Node* connection) {

	//in case there is already something in next
	if (next) {
		delete next;
	} 

	next = connection;
}

//ProductiManage class functions
//----------------------------------------------------------------	
//Construct
ProductManage::ProductManage()
{
	table = NULL;

	table = new Node * [MAX_SIZE];

	for(int i = 0; i < MAX_SIZE; i++)
	{
		table[i] = NULL;
	}
}

//copies constructor
ProductManage::ProductManage(const ProductManage & obj)
{
	for(int i = 0; i < MAX_SIZE; i++)
	{
		table[i] = NULL;
		table[i] = obj.table[i];
	}
}

//delete recursively for a arbitrary list from table
void ProductManage::delete_all(Node *& head)
{
	if(head)
	{
		delete_all(head->go_next());
		delete head;
		head = NULL;
	}
}

//Destructor
ProductManage::~ProductManage()
{
	for(int i = 0; i < MAX_SIZE; i++)
	{
		delete_all(table[i]);
	}
	delete [] table;
	table = NULL;
}

//node copy constructor calls this function to traverse the lists
void ProductManage::copy(Node *& newhead, Node * oldhead) 
{
	if(oldhead) 
	{
		newhead->connect_next(oldhead->go_next());
		copy(newhead->go_next(), oldhead->go_next());
	}

}

//Displays all the data
void ProductManage::display(Node * head)
{
	//if the head has a next to next
	if(head->go_next())
	{
		display(head->go_next());
	}

	head->display();
}

//Display Nation distribution function
void ProductManage::display_NationDistribution()
{
	//if there are no any information about Nation distribution
	if(table[0] == NULL)
	{
		cout << "There are no any information about Nation distribution to display" << endl;
	}else
	{
		display(table[0]);
	}
}

//Display Local distribution function
void ProductManage::display_LocalDistribution()
{
	//if there are no any information about Nation distribution
	if(table[1] == NULL)
	{
		cout << "There are no any information about Local distribution to display" << endl;
	}else
	{
		display(table[1]);
	}	
}

//add an arbitrary assignment recursive function
Node *& ProductManage::add_product(Node *& head)
{
	if(head->go_next())
	{
		return add_product(head->go_next());
	}

	return head;
}

//Add information about Nation distribution
bool ProductManage::add_NationDistribution(const Product & a_product)
{
	if(table[0] == NULL)
	{
		table[0] = new Node(a_product);
		return true;
	}else
	{
		Node * newnode = new Node(a_product);
		Node * temp = add_product(table[0]);
		temp->connect_next(newnode);
		return true;
	}
}	

//Add information about Local distribution
bool ProductManage::add_LocalDistribution(const Product & a_product)
{
	if(table[1] == NULL)
	{
		table[1] = new Node(a_product);
		return true;
	}else
	{
		Node * newnode = new Node(a_product);
		Node * temp = add_product(table[1]);
		temp->connect_next(newnode);
		return true;
	}
}	

Node *& ProductManage::search_name(Node *& head, char * searched_name)
{
	if(head == NULL)
	{
		return head;
	}

	if(head->compare_name(searched_name))
	{
		return head;
	}else
	{
		return search_name(head->go_next(), searched_name);
	}
}

//function to change the information by searching for a title for Nation distribution
bool ProductManage::change_NationDistribution(char * searched_name)
{
	Node * temp = search_name(table[0], searched_name);

	if(temp == NULL)
	{
		cout << "The nation distribution is not exist..." << endl;
		return false;
	}else
	{
		temp->change_delivery();
		return true;
	}
}

//function to change the information by searching for a title for Local distribution
bool ProductManage::change_LocalDistribution(char * searched_name)
{
	Node * temp = search_name(table[0], searched_name);

	if(temp == NULL)
	{
		cout << "The local distribution is not exist..." << endl;
		return false;
	}else
	{
		temp->change_delivery();
		return true;
	}
}
























