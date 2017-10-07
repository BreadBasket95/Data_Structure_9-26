/*******************************************************************************
* driver.cpp
*
* author: Rikk Anderson
* date created: 10/12/2014
* last updated: 10/12/2014
*
* This file provides an Node struct
*
*******************************************************************************/
#include <iostream>
#include <string>
#include <stdio.h>
#include <ctype.h>

#include "Node.h"
#include "Stack.h"
#include "Stack.cpp"
#include "Queue.h"
#include "Queue.cpp"

using namespace std;

string convert_to_pf(string eq);  // write the body of this method below test()
void test();  // I provided this method for you to test your covert fucniton but
              // you should do a more thorough test.

int main() {
  test();
}

void test() {
  cout << "******* Executing Converter test *******\n";
  cout << convert_to_pf("2+2") << endl;
  cout << convert_to_pf("2+2-7") << endl;
  cout << convert_to_pf("2+2*7") << endl;
  cout << convert_to_pf("2+2*7%4") << endl;
  cout << convert_to_pf("2*2-7/4") << endl;
  cout << convert_to_pf("2*(2-7)/4") << endl;
  cout << convert_to_pf("2*(2-7)/4&&8") << endl;
  cout << convert_to_pf("2*4==(2-7)/4") << endl;

  // invalid equation check
  cout << convert_to_pf("2*(2-7]/4") << endl;
  cout << convert_to_pf("[2*(2-7)/4") << endl;
  cout << convert_to_pf("[2*(2-7)/(4") << endl;
  cout << convert_to_pf(")2*(2-7)/(4") << endl;
  cout << "******************************************\n\n";

}

string convert_to_pf(string eq)
{
  Stack stackone; // The stack object that will help sort the string tokens
  Queue queueone; // The queue object that will store the final expression

  for(int count = 0; count < eq.length(); count++){

    if(isdigit(eq[count])){     // checking if the token is a numerical digit
      queueone.enqueue(eq.substr(count, 1), NULL); // If the token is a numerical digit, enqueue it with a precedence value of null
  }
    else if(eq[count] == '(') {  // If the token is a left parenthesis, push it to the stack
      stackone.push(eq.substr(count, 1), 0);
    }
    else if(ispunct(eq[count])){ // If the token is an operator...
      while(((stackone.top())&&(stackone.top()->precedence== 2))){ // And its precedence is greater than or equal to the top item of the stack...
        queueone.enqueue(stackone.pop());    // pop it from the stack and enqueue it.
        stackone.push(eq.substr(count, 1) )
      }

    }

/*  create an empty stack
  create an empty queue to represent the postfix expression
  for each token in the expression:
  if token is a number:
  append it to the postfix expression
  elif token is a left parenthesis:
  push it to the stack

  elif token is an operator:
  while (stack is not empty and the top stack item is an operator
  with precedence greater than or equal to token):
  pop and append the operator
  to the postfix expression
  push the token onto the stack

  else token must be a right parenthesis
  while(the top item on the stack is not a left parenthesis):
  pop item from the stack and append it to the postfix expression
  pop the left parenthesis while the stack is not empty
  pop an item from the stack and append it to the postfix expression */
  //string eq
  //Queue queue_one;
  //Stack stack_one;
}
return 0;
}
