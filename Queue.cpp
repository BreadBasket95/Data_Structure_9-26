/*******************************************************************************
* Queue.cpp
*
* author: Rikk Anderson
* date created: 10/12/2014
* last updated: 10/12/2014
*
* This files defines the method of the Queue class used for infix to postfix
* conversion
*
*******************************************************************************/
#include "Queue.h"

Queue::Queue() {
  front = NULL;   // creation of a null pointer, can also be set to 0 or nullptr
  rear = NULL;
};

Queue::~Queue() {
  destroy_Queue();
}

// This method removes all nodes from the structure.  This method is public for
// use outside of class methods and it is also call by the destrcutor.
void Queue::destroy_Queue() {
  Node *dnode;

  while (front != NULL) {
    dnode = front;
    front = front->next;
    delete dnode;
  }
  rear = front;
}


/****************************
* methods you must implement
****************************/


// receives a single character and a precedence value.  It then uses
// the values to create a new node and adds the node to the rear of the queue.
// NOTE: all newly created node should have their next pointer set to NULL
void Queue::enqueue(const string &item, const int &precedence) {
 temp = new Node();
 temp->data = item;
 temp->precedence = precedence;
 temp->next = nullptr;
 if(!front){
   rear = temp;
   front = temp;
 }

 else{
   rear->next = temp
   rear = rear->next;
}

// receives a pointer to a node object and uses the pointer to add the
// node to the rear of the queue.  The received node object should have
// been created using dynamic memory allocation in your convert or compute
// method or a node returned from the pop() method of your Stack class.
void Queue::enqueue(Node *node) {


}

// This method removes the front node from the queue and returns the pointer
// to that node.  During this process, the method should update the front pointer
// to point to the new front node resulting from the removal.
Node* Queue::dequeue() {


}
