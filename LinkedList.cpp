// LinkedList.cpp
// Written by : SENG1120 
// Written by : NI ZENG
// Modified   : 13/09/2020
// 
// 
// This file should be used in conjunction with ASSISSMENT 1 for SENG1120

#include <string>
#include "LinkedList.h"
#include "Node.h"
#include <cstdlib>
#include <iostream>

//make a function for ostream so that we get <<string<< output.
	void LinkedList::output(std::ostream& out )const 
	{
		Node* current = head;
				while(current != NULL )
				{					
					out << current ->get_data() <<" ";
					current = current ->get_next();
				}									
	}
// call out the output function 	
	std::ostream& operator << ( std::ostream& out, const LinkedList& l )
	{
		l.output(out);
		return out;
	}
	
	//overload operator += : add list2 to list1.
	void LinkedList::operator += ( LinkedList& l)
	{			
		//	move_to_head ();
		l.move_to_head();
		int lsize = l.size();
		for(int i=0;i<lsize;i++ )		// loop within the list size;
		{
			std::string temp =l.get_current();
			add_to_tail(temp);			
						
			l.forward();		//	forward();
			temp = "";	  		//set temp back to empty string.
		}									
	}
	

	//create an empty linked list
	LinkedList::LinkedList()
	{
		head = NULL;
		tail = NULL;
		current = NULL;
		list_length= 0;
	}
	
	//create a linked list with data
	LinkedList::LinkedList(value_type& data)
	{
		head = new Node(data);
		tail = head;
		current = tail;
		list_length = 1;
		
	}
	//destructor(ensure all Nodes are removed from the heap when a linked list is deleted).
	LinkedList::~LinkedList()
	{
		while(head !=NULL)
			remove_from_head();
		tail = NULL;
	}
	// function for adding string into the nodes. each word sore as one node.
	void LinkedList::add(const value_type& data)
	{		
		value_type word = "";
		//count the all the words that have enter and assign them to each node
		for (int i = 0; data[i] != '\0';i++)
		{				
			if (data[i] != ' ')
			{
				word += data[i];
			}
			else 
			{
				add_to_tail(word);
				word = "";
				
			}			
		}
		add_to_tail(word);		
	}	
	
	//remove node from linkedlist.
	void LinkedList::remove(const value_type& data)
	{
		move_to_head();
		while(current !=NULL )
		{
			if(current->get_data()!= data )
			{
				current = current->get_next();
			}
			else if(current->get_data() == data)
			{	
				
				current->get_previous()->set_next( current->get_next() );
				if(current -> get_next() !=NULL)
				{
					current->get_previous()->set_next( current->get_next() );
					current->get_next()->set_previous( current->get_previous() );
				}
				else 
				{
					current->get_previous()->set_next (NULL) ;
					tail = current ->get_previous();
				}
				delete current;
				current = head;
				list_length--;	// once the node remove, list length - 1 .
			}
		}
	}

	// count function to count the number of node.
	int LinkedList::count(const value_type data)
	{	
		//set current back to head.
		move_to_head();		
		int count =0;	//set count as integer and equal to 0.
		
		while(current !=NULL )
		{
			if(current->get_data()== data )  //search if the linkedlist contains the node with given data.
			{
				
				count ++;	//if fount the matching node, count +1;
			}
			forward();			//move to the next node of the linkedlist.		
				
				
		}
		return count;	//return the number of same nodes.
	}
//	
//	void LinkedList::swap(LinkedList word1, value_type& word2 )  
//	{  
		
//		remove_from_head(word2);  
//		add_to_tail(word1);
//	}
	
//Below is an uncomplied function, i just add for the file to compile .		
	void LinkedList::sort() 
	{	
//		move_to_head();
//		value_type& wordCurrent = current;
//		value_type& wordNext = current->get_Next();
//		
//		wordCurrent = current -> get_data();
//		wordNext = current -> get_data();
//		
//		
//		int compare (const string& str) const noexcept;
//		for (wordCurrent = head; wordCurrent->get_Next() != NULL ; wordCurrent->get_Next() )
//		{
//			for (wordNext = wordCurrent->get_Next() ; wordNext !=NULL ; wordNext= wordNext->get_Next();)
//			{
//				if(wordCurrent.compare(wordNext)>0 )
//				{
//					std::cout<<"Swap !"<< std::endl;
//					swap(wordCurrent,wordNext);
//				}
//				else if(wordCurrent.compare(wordNext)<0)
//				{
//					std::cout <<"Dont Swap !" << std::endl;	
//					
//				}
//				else if(wordCurrent.compare(wordNext)==0)
//				{
//					std::cout <<"leave !" <<std::endl;
//					
//				}
//			}			
//		}
//	-----------------------------------
			
	}	
//-----------------------------------------------------------------------------------------
//	function for add node to the head of the linkedlist.
	void LinkedList::add_to_head(value_type& data)
	{
		//add Node for empty list
		if(list_length == 0)
		{
			head = new Node(data);
			tail = head;
			current = tail;
			list_length = 1;
		}
		else
		{
			//create new Node on the heap
			Node* head_insert = new Node (data);
			
			//set the head"previous " ptr ->to the new head and set the next Node"next" ptr ->to the Node at
			//the current head.
			head->set_previous(head_insert);
			head_insert->set_next(head);
			
			//set the head_ptr to the new Node
			head = head_insert ;
			
			//add 1 list to the list length 
			list_length++;
			
			//set to NULL
			head_insert = NULL;				
			
		}			
	}
//	function for add node to the tail of the linkedlist.	
	void LinkedList::add_to_tail(value_type& data)
	{
		//add Node for empty list
		if(list_length == 0)
		{
			head = new Node(data);
			tail = head;
			current = tail;
			list_length = 1;
		}
		else
		{
			//create new Node on the heap
			Node* tail_insert = new Node (data);
			
			//set the head"previous " ptr ->to the new head and set the next Node"next" ptr ->to the Node at
			//the current head.
			tail->set_next(tail_insert);
			tail_insert->set_previous(tail);
			
			//set the head_ptr to the new Node
			tail = tail_insert ;
			
			//add 1 list to the list length 
			list_length++;
			
			//set to NULL
			tail_insert = NULL;							
		}			
	}
	
//	function for remove from head of the linkedlist.	
	void LinkedList::remove_from_head()
	{
		//no action for empty list
		if(list_length ==0 )
		{
			return;
		}
		else if (list_length ==1)
		{
			delete head;
			head=NULL;
			tail=NULL;
			current = NULL;
			list_length--;
			return;		
		}
		else
		{
			//make a temp_head_ptr and sent it as the current head_ptr
			Node* temp_head_ptr = head;
			
			//rearrange the head_ptr for the list
			head = temp_head_ptr ->get_next();
			
			//remove temp_head_ptr
			delete temp_head_ptr;
			
			//remove the list length
			list_length --;
			
			//set temp_head back to NULL;
			temp_head_ptr = NULL;			
		}		
	}	
//	function for remove from tail of the linkedlist.	
	void LinkedList::remove_from_tail()
	{
		//no action for empty list
		if(list_length ==0 )
		{
			return;
		}
		//delete the only Node if only 1 Node existed.
		else if (list_length ==1)
		{
			delete head;
			head=NULL;
			tail=NULL;
			current = NULL;
			list_length--;
			return;		
		}
		else
		{
			//make a temp_head_ptr and sent it as the current head_ptr
			Node* temp_tail_ptr = tail;
			
			//rearrange the tail_ptr for the list
			tail = temp_tail_ptr ->get_previous();
			
			//remove temp_tail_ptr
			delete temp_tail_ptr;
			
			//remove the list length
			list_length --;
			
			//set temp_tail_ptr back to NULL;
			temp_tail_ptr = NULL;			
		}		
	}
	
	


	LinkedList::value_type LinkedList::get_current()
	{
			return current->get_data();
	}		
	
//	below are the function to control the movement current pointer.	
	void LinkedList::forward()
	{
		current = current->get_next();
	}
	void LinkedList::back()
	{
		current = current->get_previous();
	}
	void LinkedList::move_to_head()
	{
		current = head;				
	}	
	void LinkedList::move_to_tail()
	{
		current = tail;		
	}

// linkedlist size;	
	std::size_t LinkedList::size()
	{
		return list_length;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	