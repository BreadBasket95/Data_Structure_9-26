/*******************************************************************************
* Queue.h
*
* author: Rikk Anderson
* date created: 9/27/2017
* last updated: 9/27/2017
*
* This files defines a Queue class used for infix to postfix conversion
*
*******************************************************************************/
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "Node.h"

class Queue {
private:
	Node* front;  // the head pointer of the linked list-based queue
	Node* rear;   // the tail pointer of the linked list-based queue

public:
	Queue();    // the constructor
	~Queue();   // the destructor

	void destroy_Queue(); // removes all elements from the queue

						  // *** methods you must implement
						  // the item and precedence parameters are made const to
						  // prevent and accidental modification of the parameters
	void enqueue(const string &item, const int &precedence);
	void enqueue(Node *node);

	Node* dequeue();  // removes and returns a front node from the queue

};

#endif
