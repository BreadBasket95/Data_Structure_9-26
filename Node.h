/*******************************************************************************
* Node.h
*
* author: Rikk Anderson
* date created: 9/27/2017
* last updated: 9/27/2017
*
* This file provides a Node struct
*
*******************************************************************************/
#ifndef NODE_H
#define NODE_H
#include<string>
using std::string;

struct Node {
  string data;    // stores an operand of operator
  int precedence; // store precedence is data is an operator
  Node *next;     // a pointer to the next node
};

#endif
