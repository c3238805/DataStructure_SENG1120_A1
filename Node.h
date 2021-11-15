// Node.h
// Written by : SENG1120 Student c3238805
// Written by : NI ZENG
// Modified   : 13/09/2020
// Define a class Node (double-linked)that can be used to implement a linked list-based structure. 
// This file should be used in conjunction with Assignment 1 for SENG1120.

#ifndef NIZENG_NODE //macroguards
#define NIZENG_NODE //macroguards

#include <string> //provides string .

#include <cstdlib> //provides site_t and NULL.


class Node
{
	
	
	public :		
		//TYPEDEF
		typedef std::string value_type ;
		//CONSTRAUCTION
		Node();
		Node(const value_type& initial_data = value_type()  , Node* initial_next = NULL, Node* initial_prev = NULL);
		//DESTRUCTOR
		~Node();
		
//--------------------------------------------------------------------------------------------------------		
		//MODIFICATION MEMBER FUNCTION
		void set_data(const value_type& new_data);		//set data into node;
		void set_next(Node* next_link);					//set next data into node;
		void set_previous(Node* previous_link);			//set previous data into node ;
		void set_current(Node* current_link);			//set current data as data;
		
		//CONSIANT MEMBER FUNCTION		
		value_type get_data() const;					
		const Node* get_previous () const;					
		const Node* get_next() const;	
		const Node* get_current() const;	
		
		//NON CONSIANT MEMBER FUNCTION		
		Node* get_previous();	
		Node* get_next();		
		Node* get_current();

	private:
		//private member of the Node class;
		value_type data;		
		Node* next;
		Node* previous;
		Node* current;
	
};



#endif