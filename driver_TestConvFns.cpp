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
#include <map>

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
  map <string, int> dictionary;
  dictionary["*" "/" "%"] = 2;
  dictionary["+" "-"] = 1;
  dictionary["(" "["] = 0;

  /*precedence =2, for *, /, and %
precedence =1, for + and –
precedence =0, for ( and [ */

  Stack stackone; // The stack object that will help sort the string tokens
  Queue queueone; // The queue object that will store the final expression

  for(int count = 0; count < eq.length(); count++){
    if(isdigit(eq[count])){     // checking if the token is a numerical digit
      queueone.enqueue(eq.substr(count, 1), NULL); // If the token is a numerical digit, enqueue it with a precedence value of null
  }
    else if(eq.substr(count, 1) == "(") {  // If the token is a left parenthesis, push it to the stack
      stackone.push(eq.substr(count, 1), 0);
    }
    else if(ispunct(eq[count])){ // If the token is an operator...
      // the code below checks if the top item of the stack exists, and if it is an operator
      // at the same time by checking the precedence value of the top object, because
      // it would return null if it is empty, or if it is a non-operator as specified on line 69
      while((stackone.top())&&(stackone.top()->precedence > 0) && stackone.top()->precedence >= dictionary[eq.substr(count, 1)]){ // And its precedence is greater than or equal to the top item of the stack...
        queueone.enqueue(stackone.pop());    // pop it from the stack and enqueue it.
      }
      stackone.push(eq.substr(count, 1), dictionary[eq.substr(count, 1)]);
    }
    else if(stackone.top()->data != ("(")){
        queueone.enqueue(stackone.pop());
        }
        if(stackone.top()->data == "("){
          stackone.pop();
        }
      }
    while(stackone.top()){
      queueone.enqueue(stackone.pop());
    }

return 0;
}
