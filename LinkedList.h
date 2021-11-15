// Node.h
// Written by : SENG1120 Student c3238805
// Written by : NI ZENG
// Modified   : 13/09/2020
// Define a class LinkedList that can be used to implement a linked list-based structure. 
// This file should be used in conjunction with Assignment 1 for SENG1120.

//macroguards
#ifndef NIZENG_A1
#define NIZENG_A1

#include <iostream>
#include <string>
#include <cstdlib> //provides size_t
#include "Node.h"

class LinkedList
{
	
	
	public :	
		void operator += (  LinkedList& l);	//Overload operator.
		//TYPEDEF
		typedef std::string value_type; // Name type 'std::string' to 'value_type' .
		
		//CONSTRUCTION
		LinkedList();		
		LinkedList(value_type& data);
		//DESTRUCTOR
		~LinkedList();
	
		//MEMBER FUNCTIONS
		void add (const value_type& data);
		void remove(const value_type& data);	
		int count(const value_type data);
		void sort();
//		void swap(value_type& word1, value_type& word2 ) ;
		
		
		void output(std::ostream& out )const;	//Function to output the info contained in each node.
//---------------------------------------------------------------------------------------		
		void add_to_head(value_type& data);
		void add_to_tail(value_type& data);
		void remove_from_head();
		void remove_from_tail();
		
		void forward();
		void back();
		void move_to_head();
		void move_to_tail();
				
			

		value_type get_current();		
		
		std::size_t size();
		
		std::size_t list_length;
		
		
		
		
	private :
		Node* head;
		Node* tail;
		
		Node* current;
		
	
};
std::ostream& operator << ( std::ostream& out, const LinkedList& l );

// close the macroguard
#endif 