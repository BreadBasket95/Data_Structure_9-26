/*******************************************************************************
* Stack.h 
*
* author: Rikk Anderson
* date created: 9/27/2017
* last updated: 9/27/2017
*
* This files defines a Stack class used for infix to postfix conversion
* 
*******************************************************************************/
#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "Node.h"

class Stack {
  private:
    Node *tos;  // the head pointer of the linked list-based stack
    
  public:
    Stack();    // the constructor
    ~Stack();   // the destructor
    
    void destroy_Stack(); // removes all elements from the stack

    // *** methods you must implement
    // the item and precedence parameters are made const to 
    // prevent and accidental modification of the parameters
    void push(const string &item, const int &precedence);
    void push(Node *node);
    
    Node* pop();        // removes and returns the top node or NULL if stack is empty
    Node* top() const;  // returns a pointer to the top node (allows you to look at it)
                        // returns NULL of stack is empty
    
};

#endif
