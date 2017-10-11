/*******************************************************************************
* Stack.cpp
*
* author: Rikk Anderson
* date created: 10/12/2014
* last updated: 10/12/2014
*
* This files defines the method of the Stack class used for infix to postfix
* conversion
*
*******************************************************************************/
#include "Stack.h"
#include "Node.h"

Stack::Stack() {
	tos = NULL; // creation of a null pointer, can also be set to 0 or NULL
};

Stack::~Stack() {
	destroy_Stack();
};

// This method removes all nodes from the structure.  This method is public for
// use outside of class methods and it is also call by the destrcutor.
void Stack::destroy_Stack() {
	Node *dnode;

	while (tos != NULL) {
		dnode = tos;
		tos = tos->next;
		delete dnode;
	}
}


/****************************
* methods you must implement
****************************/

// receives a single character and a precedence value.  It then uses
// the values to create a new node and adds the node to the top of the stack.
// NOTE: all newly created node should have their next pointer set to NULL
void Stack::push(const string &item, const int &precedence) {
	Node *new_node = NULL; // dynamically allocating a node struct object "newnode" that will be added to the queue
	new_node = new Node;
	new_node->precedence = precedence; // assigning values to the node object
	new_node->data = item;             // assigning values to the node object
	new_node->next = NULL;
	if (!tos) {       // this function checks if the top of the stack exists, and makes the new node the top if it doesn't
		tos = new_node;
		new_node->next = NULL;
	}
	else {           // if the top of the stack already exists, that is if tos already points to a node,
		new_node->next = tos;            // then this function adds another node to the top of stack
		tos = new_node;
	}
}

// receives a pointer to a node object and uses the pointer to add the
// node to the top of the stack.  The received node object should have
// been created using dynamic memory allocation in your convert or compute
// method or a node returned from the dequeue() method of your Queue class.
void Stack::push(Node *node) {
	if (tos) {         // checking if the top of the stack exists.
		node->next = tos;
		tos = node;
	}
	else {
		tos = node;
		node->next = NULL;
	}
}



// This method removes the top of the stack and returns the pointer to that node.
// During this process, the method should update the tos pointer to point to the
// new top of stack node resulting from the removal.
Node* Stack::pop() {
	
	Node *temp = NULL;
	if (tos) { // If the stack exists, move the top of the stack to the next element
		temp = tos;
		tos = tos->next;
	}
	temp->next = NULL;
	return temp;
}


// This method returns a pointer to the top of the stack.  In contrast to pop(),
// this method DOES NOT remove the top of stack.  The use of const here prevents
// the user from modifying the pointer (and the object) returned from this method.
Node* Stack::top() const {
	return tos;
}
