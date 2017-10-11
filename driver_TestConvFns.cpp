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

int get_precedence(string token);
string convert_to_pf(string eq);
string transform(Queue q);
              // write the body of this method below test()
void test();  // I provided this method for you to test your covert fucniton but
              // you should do a more thorough test.

int main() {
  test();
  cout << "end";
  return 0;
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

/*  map <string, int> dictionary;
  dictionary["*"] = 6; dictionary["/"] = 6; dictionary["%"] = 6;
  dictionary["+"] = 5; dictionary["-"] = 5;
  dictionary["<"] = 4; dictionary[">"] = 4;
  dictionary["=="] = 3; dictionary["!="] = 3;
  dictionary["&&"] = 2;
  dictionary["||"] = 1;
  dictionary["("] = 0; dictionary["["] = 0; dictionary[")"] = 0; dictionary["]"] = 0;
  dictionary["!"] = 10; dictionary["#"] = 10; dictionary["\""] = 10; dictionary["$"] = 10; dictionary["\'"] = 10; dictionary[","] = 10; dictionary["."] = 10; dictionary[":"] = 10;
  dictionary[";"] = 10; dictionary["?"] = 10; dictionary["@"] = 10; dictionary["`"] = 10; dictionary["~"]= 10; */


  Stack stackone; // The stack object that will help sort the string tokens
  Queue queueone; // The queue object that will store the final expression


  for(unsigned int count = 0; count < eq.length(); count++)
  {
    if(isdigit(eq[count])) // checking if the token is a numerical digit
    {
    //  cout << "digit ";
      queueone.enqueue(eq.substr(count, 1), -1); // If the token is a numerical digit, enqueue it with a precedence value of -1

    }
    else if(eq[count] == '(' || eq[count] == '[') // If the token is a left parenthesis, push it to the stack
    {
    //  cout << "left parenthesis";
      //cout << eq.substr(count, 1);
      stackone.push(eq.substr(count, 1), 0);
//      cout << stackone.top()->precedence;
//      cout << stackone.top()->data;
    }
    else if(get_precedence(eq.substr(count, 1)) >= 1 ) // == "*" || eq.substr(count, 1) == "+" || eq.substr(count, 1) == "-" || eq.substr(count, 1) == "%" || eq.substr(count, 1) == "/" || eq.substr(count, 1) == ">" || eq.substr(count, 1) == "<") // || eq.substr(count, 1) == "*" || eq.substr(count, 1) == "*" || ) // If the token is an operator...
    {
//      cout << stackone.top()->precedence;
//      cout << stackone.top()->data;

      //cout << "working ";
    //  cout << stackone.top()->data;
      //cout << stackone.top()->precedence;
        //the code below checks if the top item of the staprecedenceck exists, and if it is an operator
      while(stackone.top() && stackone.top()->precedence >= get_precedence(eq.substr(count, 1)))// And its precedence is greater than or equal to the top item of the stack...
        {
            cout << "top of stack has larger precedence than token ";
      //    cout << eq.substr(count, 1);
            queueone.enqueue(stackone.pop());    // pop it from the stack and enqueue it.
        }
      stackone.push(eq.substr(count, 1), get_precedence(eq.substr(count, 1)));
    }
else if(eq[count] == ')')
{
  //cout << ")";
   while(stackone.top() && stackone.top()->data != "(")
   {
     queueone.enqueue(stackone.pop());
    }
    stackone.pop();
  }
while(stackone.top())
{
  queueone.enqueue(stackone.pop());
}

}
  return "";
}

int get_precedence(string token){
  if(token == ("*") || token == "/" || token == "%"){
    return 6;
  }
  if(token == "+" || token == "-"){
    return 5;
  }
  if(token == "<" || token == ">"){
    return 4;
  }
  if(token == "==" || token == "!="){
    return 3;
  }
  if(token == "&&"){
    return 2;
  }
  if(token == "||"){
    return 1;
  }
  if(token == "(" || token == "["){
    return 0;
  }
  else return -1;
}

string transform(Queue q){

    return "";
}
