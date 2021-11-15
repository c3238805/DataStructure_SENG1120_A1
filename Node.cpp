// linkedlist.cpp
// Written by : SENG1120 student
// Written by:NI ZENG
// Modified   : 13/09/2020
// 
// 
// Node function.
// This file should be used in conjunction with Assigment 1 for SENG1120

#include "Node.h"
#include <cstdlib>

//overload operator <<: display all list.


	
	//CONSTRAUCTION
	
	Node::Node(const value_type& initial_data  , Node* initial_next , Node* initial_prev )
	{
		data = initial_data;		
		next = initial_next;
		previous = initial_prev;
		
	}
	//DESTRUCTOR
	Node::~Node()
	{
		next = NULL;		
		previous = NULL;
		
	}
//---------------------------------------------------------------------------------------------------	
	//MODIFICATION MEMBER FUNCTION
	void Node::set_data(const value_type& new_data)		
	{data = new_data;}
	
	void Node::set_next(Node* next_link)					
	{next = next_link;}
	
	void Node::set_previous(Node* previous_link)			
	{previous = previous_link;}
	
	void Node::set_current(Node* current_link)
	{current =current_link;}
	//CONSIANT MEMBER FUNCTION
	
	Node::value_type Node::get_data() const		
	{return data;}	
	
	const Node* Node::get_previous () const		
	{return previous;}
	
	const Node* Node::get_next() const			
	{return next;}
	
	const Node* Node::get_current() const			
	{return current;}
	
	//NON CONSIANT MEMBER FUNCTION		
	Node* Node::get_previous()		
	{return previous;}
	
	Node* Node::get_next()			
	{return next;}	
	
	Node* Node::get_current()
	{return current;}
