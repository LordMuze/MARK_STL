/*!*************************************************************************
****
\file list.cpp
\author Muhammad Muslinmin Bin Mohd Saleh
\par email: 2201360@sit.singaporetech.edu.sg
\par Course: HLP2
\par Programming Lab 10
\date 28-03-2023
\brief
    This program implements singly linked list base class member functions and data (protected and public) would be shared to its derived classes i.e.
	the doubly linked list.

	Some of the functions implemented in the singly linked list is implemented in the doubly linked list
****************************************************************************/

#include <iostream>
#include <iomanip>
#include "list.h"

namespace hlp2 {
	/*!*************************************************************************
    **** 
    \brief
		Sllist constructor
    \param //Initialize Head
    ****************************************************************************
    ***/
	sllist::sllist(): head(nullptr) {

	}
	/*!*************************************************************************
    **** 
    \brief
		Dllist constructor
    \param //Initialize tail
    ****************************************************************************
    ***/
	dllist::dllist() :
		tail(nullptr) {}
	sllist::~sllist(){
		slnode* current = head;
        while(current != nullptr){
            slnode* tmp = current->next;
            delete current;
            current = tmp;
        }
        delete current;
	}
	/*!*************************************************************************
    **** 
    \brief
		Removes the first element in a singly linked list
    ****************************************************************************
    ***/
	void sllist::pop_front(){
		if(head == nullptr){
			return;
		}
		slnode* front_del = head;
		head = head->next;
		delete front_del;
	}
	/*!*************************************************************************
    **** 
    \brief
		Removes the first element in a doubly linked list
    ****************************************************************************
    ***/
	void dllist::pop_front(){
		if(head == nullptr){
			return;
		}
		dlnode* front_del = static_cast<dlnode*>(head);
		head = head->next;
		delete front_del;
	}
	/*!*************************************************************************
    **** 
    \brief
		slnode constructor
    ****************************************************************************
    ***/
	sllist::slnode::slnode(int num, slnode* itr) {
		value = num;
		next = itr;
	}
	/*!*************************************************************************
    **** 
    \brief
		dlnode constructor
    ****************************************************************************
    ***/
	dllist::dlnode::dlnode(dlnode* prevItr , int val, dlnode* itr){
		prev  = prevItr;
		value = val;
		next = itr;
	}
	/*!*************************************************************************
    **** 
    \brief
		sllist copy constructor
		Copies the contents from the sllist into a list of the same type
    ****************************************************************************
    ***/
	sllist::sllist(sllist const& cpy){
		slnode* node = cpy.head;
		if(node == nullptr){
			return;
		}
		while(node){
			push_back(node->value);
			node = node->next;
		}
	}
	/*!*************************************************************************
    **** 
    \brief
		dllist destructor
		Destroys the dllist at the end of the scope
    ****************************************************************************
    ***/
	dllist::~dllist(){

    }
	/*!*************************************************************************
    **** 
    \brief
		singly linked list print function
		prints the content of singly linked list
    ****************************************************************************
    ***/
	void sllist::print() const
	{
		slnode const* l_pCur = head;
		while (l_pCur) {
			std::cout << l_pCur->value << "    ";
			l_pCur = l_pCur->next;
		}
		std::cout << "\n";
	}
	/*!*************************************************************************
    **** 
    \brief
		Pushes new node at the front of a singly linked list
	\param
		New node with the value to be pushed 
    ****************************************************************************
    ***/
	void sllist::push_front(int value){
		slnode* new_head = new slnode;
		new_head->next = head;
		new_head->value = value;
		head = new_head;
	}
	/*!*************************************************************************
    **** 
    \brief
		Pushes new node at the front of a doubly linked list
	\param
		New node with the value to be pushed 
    ****************************************************************************
    ***/
	void dllist::push_front(int value){
		dlnode* new_head = new dlnode{nullptr, value, static_cast<dlnode*>(head)};
		head = new_head;
	}
	/*!*************************************************************************
    **** 
    \brief
		Pushes a node at the back of the singly linked list
	\param
		New node with the value to be pushed 
    ****************************************************************************
    ***/
	void sllist::push_back(int value){
		if (head == nullptr){
			head = new slnode;
			head->value = value;
			head->next = nullptr;
			return;
		}
		slnode* node = head;
		while(node){
			if(node->next == nullptr){
				node->next = new slnode{value, nullptr};
				node->next->value = value;
				node->next->next = nullptr;
				return;
			}
			node = node->next;
		}
		// tail->next = new slnode{ value, next };
		// node<T>* lastNode = tail->next;
		// tail = lastNode;		
	}
	/*!*************************************************************************
    **** 
    \brief
		Pushes a node at the back of the doubly linked list
	\param
		New node with the value to be pushed 
    ****************************************************************************
    ***/
	void dllist::push_back(int value){
		if (head == nullptr){
			head = new slnode;
			head->value = value;
			head->next = nullptr;
			return;
		}
		slnode* node = head;
		while(node){
			if(node->next == nullptr){
				node->next = new slnode{value, nullptr};
				node->next->value = value;
				node->next->next = nullptr;
				return;
			}
			node = node->next;
		}
		// tail->next = new slnode{ value, next };
		// node<T>* lastNode = tail->next;
		// tail = lastNode;		
	}
	/*!*************************************************************************
    **** 
    \brief
		Get the size of the singly linked list
	\return
		Returns a size_t size of the singly linked list
    ****************************************************************************
    ***/
	size_t sllist::size() const {
		size_t cnt{0};
		slnode* itr = head;
		while (itr != nullptr) {
			cnt++;
			itr = itr->next;
		}
		return cnt;
	}
	/*!*************************************************************************
    **** 
    \brief
		Doubly linked list copy constructor
    ****************************************************************************
    ***/
	dllist::dllist(dllist const& list):  sllist(),
	tail(nullptr) {
        dlnode* current = static_cast<dlnode*> (list.head);				
		if(list.head == nullptr){
			return;
		}

		while(current != nullptr){
			push_back(current->value);
			current =  static_cast<dlnode*> (current->next);
		}
        tail = current; // sets the tail of the new list       
    }
	/*!*************************************************************************
    **** 
    \brief
		Inserts a value at the position specified in the doubly linked list
	\param
		Value to be inserted into a new node at the position specified
		Position to be specified

		If position is more than the number of nodes in the dllist, inserts value after
		the last element of the dllist instead
    ****************************************************************************
    ***/
	void dllist::insert(int value, size_t position){
		// if first index	
		if(position == 0){
			push_front(value);
			return;
		}
		// if index more than last or the last index
		if(position >= this->size()){
			push_back(value);
			return;
		}
		//if in between 0 to last index
		dlnode* new_node = new dlnode;
		new_node->value = value;					

		dlnode* current = static_cast<dlnode*>(head);						
		for (size_t i{0}; i < position - 1; ++i){
			current = static_cast<dlnode*>(current->next);				
		}
		//dlnode* current_next = static_cast<dlnode*>(current->next);
		new_node->next = current->next;
		//new_node->prev = current; //..
		//current_next->prev = new_node; //..
		current->next = new_node;					
	}
	/*!*************************************************************************
    **** 
    \brief
		Inserts a value at the position specified in the singly linked list
	\param
		Value to be inserted into a new node at the position specified
		Position to be specified

		If position is more than the number of nodes in the sllist, inserts value after
		the last element of the sllist instead
    ****************************************************************************
    ***/
	void sllist::insert(int value, size_t position){
			
		if(position == 0){
			push_front(value);
			return;
		}
		if(position >= this->size()){
			push_back(value);
			return;
		}

		slnode* new_node = new slnode;
		new_node->value = value;					

		slnode* current = head;						
		for (size_t i{0}; i < position - 1; ++i){
			current = current->next;				
		}

		new_node->next = current->next;						
		current->next = new_node;										
	}
	/*!*************************************************************************
    **** 
    \brief
		Clears the singly linked list by removing removing the front
		node in each iteration until the list is empty

    ****************************************************************************
    ***/
	void sllist::clear(){
		slnode* current = head;
		while(current){
			pop_front();
			current = head;
		}
	}

	//..
	/*
	void sllist::remove_first(int value){
		if(this->size() == 0){								// if list is empty, return
			return;
		}
		if(!head){
			return;
		}
		//slnode* node = head->next;
		slnode* node_prev = head;
		//head, the first case
		if(node_prev->value == value){
			// if its the first object and the only object of the list
			if(node_prev->next == nullptr){
				delete head;
				head = nullptr;
				return;
			}else{
				// if its the first object and there are other objects in the list
				slnode* temp_head = head->next;
				delete head;
				head = temp_head;
				return;
			}
		}
		// while(node){
		// 	if(node == nullptr){
		// 		return;
		// 	}
		// 	if(node->value == value){
		// 		node_prev->next = node->next;
		// 		//delete node;
		// 		return;
		// 	}
		// 	node_prev = node->next;
		// 	node = node->next;
		// }
	}
	*/
	/*!*************************************************************************
    **** 
    \brief
		Removes the first matching element value in the singly linked list
	\param
		Matching element and value to be removed from the linked list
    ****************************************************************************
    ***/
	void sllist::remove_first(int value)
{
    // If the list empty return
    if (head == nullptr) {
        return;
    }

    slnode* curr = head;
    slnode* prev = nullptr;

    // iterate list until value is found or end of list
    while (curr != nullptr && curr->value != value) 
    {
        prev = curr;
        curr = curr->next;
    }

    // if value found, remove 
    if (curr != nullptr) 
    {
        if (prev != nullptr) // if element is not the first 
        { 
            prev->next = curr->next; // point the previous node to the next node
        } 
        else // if element is the first
        { 
            head = curr->next; // update head pointer
        }
        delete curr; // free mem
    }
}
	

	/*
	void dllist::remove_first(int value){
		if(this->size() == 0){								// if list is empty, return
			return;
		}
		dlnode* head_dl = static_cast<dlnode*>(head);
		dlnode* current = static_cast<dlnode*>(head);									// initialise node current to head
		while(current != nullptr && current->value != value){	// iterate thru list until nullptr and current value is the specified value
			current = static_cast<dlnode*>(current->next);
		}

		if(current == nullptr){									// if no such node found and current reach end of list, return
			return;
		}

		if(current == head_dl){									// if current matches head, remove
			head_dl = static_cast<dlnode*>(current->next);
			if(head_dl != nullptr){								
				head_dl->prev = nullptr;
			}
			if(tail == current){							
				tail = nullptr;
			}
			delete current;
			return;
		}else{
			dlnode* current_next = static_cast<dlnode*>(current->next);
			dlnode* current_prev = static_cast<dlnode*>(current->prev);				
			current_prev->next = static_cast<dlnode*>(current->next);				
			if(current_next != nullptr){						// if current next ptr is not nullptr, then the prev ptr of the node after current points to node before current
				current_next->prev = current_prev;
			}
			if(tail == current){								// if node to remove is at tail of list, remove
				tail = current->prev;							// tail point to node before current
			}
		}
		delete current;											// remove current node from list
	}*/
	/*!*************************************************************************
    **** 
    \brief
		Removes the first matching element value in the doubly linked list
	\param
		Matching element and value to be removed from the linked list
    ****************************************************************************
    ***/
	void dllist::remove_first(int value){
		if(this->size() == 0){
			return;
		}
		//first node
		
		dlnode* head_dl = static_cast<dlnode*>(head);
		if(head_dl->value == value){
			//if node is only object in the list
			if(head_dl->next == nullptr){
				delete head_dl;
				head_dl = nullptr;
			}else{
				//if its the first object in the list amongst other objects
				dlnode* temp_head = static_cast<dlnode*>(head_dl->next);
				delete head_dl;
				head_dl = temp_head;
			}
			head = static_cast<slnode*>(head_dl);
			return;
		}
		//mid - last node
		dlnode* node = static_cast<dlnode*>(head);
		dlnode* node_prev = static_cast<dlnode*>(head);
		int count = 0;
		while(node){
			if(node->value == value){
				//if last node
				if(node->next == nullptr){
					dlnode* prev_node = static_cast<dlnode*>(node_prev);
					prev_node->next = nullptr;
					tail = prev_node;
					delete node;
					break;
				}else{
					dlnode* prev_node = static_cast<dlnode*>(node_prev);
					prev_node->next = node->next;
					delete node;
					break;
				}

			}
			if(count == 1){
				node_prev = static_cast<dlnode*>(node_prev->next);
			}else{
				++count;
			}
			node = static_cast<dlnode*>(node->next);
		}
	}
} // end namespace hlp2