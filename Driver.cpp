// Update 10-11-17 by Author Marc Moore
// This driver file demonstrates the functionality of the convert_to_pf function
// The function takes a mathematical expression in infix notation as a string 
// and return returns a string in postfix notation, while checking for errors.

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
#include "Queue.h"


using namespace std;

int get_precedence(string token);     
string convert_to_pf(string eq);
string convert_output(int size, Queue q);   // Function to combine queue data values into a string
bool isparenth(string token);			// A function to check

			  // write the body of this method below test()
void test();  // I provided this method for you to test your covert fucniton but
			  // you should do a more thorough test.

int main() {
	test();
	cout << "end";
	system("pause");
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
	cout << eq << ": ";
	Stack s;
	Queue q;
	int q_size = 0;
	for (unsigned int index = 0; index < eq.length(); index++) // A for loop for iterating through the string
	{
		if (eq[0] == ')' || eq[0] == ']') {  // If the first item is an unmatched bracket or parenthesis, returns "INVALID"
			return "INVALID";
		}
		string character;    // Variable for storing the token
		bool is_digit = isdigit(eq[index]);  // Checks if the token is a digit 

		if (get_precedence(eq.substr(index, 2)) > 0) { // If the token is an operator containing 2 characters, update the character
			character = eq.substr(index, 2);
		}
		else {
			character = eq.substr(index, 1);
		}
		
		int precedence;

		if (!is_digit) {		// If the token isn't a number, get its precedence 
			precedence = get_precedence(character); 
		}

		if (is_digit) {
			q.enqueue(character, -1); // If the token is a digit, enqueue it with a precedence of -1
			q_size++;				// increment the counter to keep track of the size of the queue
		}

		else if (precedence == 0) { // '(' or '['
			s.push(character, precedence);
		}

		else if (precedence > 0) { // not ')' or ']' or a number
			while (s.top() && s.top()->precedence >= precedence) {
				q.enqueue(s.pop());
				q_size++;
			}
			s.push(character, precedence);
		}

		else if (character == ")" ){      // if token is a right parenthesis, and the top of the stack isn't a left parenthesis
			while (s.top()->data != "(")
			{
				q.enqueue(s.pop());			// Enqueue to top of the stack
				q_size++;
			}
			if (s.top()->data == "(") { // Remove the left parenthesis from the stack
				s.pop();
			}
		}

	}
	while (s.top()) {      // Pop the entire stack onto the queue 
		q.enqueue(s.pop());
		q_size++;
	}

	cout << "result: ";
	return convert_output(q_size, q); //function call to
}
 
bool isparenth(string token) { // A function to check if the token is a parenthesis or a bracket

	if (token == "(")
		return true;
	else if (token == "[")
		return true;
	else if (token == "]")
		return true;
	else if (token == ")")
		return true;
	else {
		return false;
	}
	
}

int get_precedence(string token) {  // A function for assigning operators precedence

	if (token == "*" || token == "/" || token == "%") {
		return 6;
	}
	if (token == "+" || token == "-") {
		return 5;
	}
	if (token == "<" || token == ">") {
		return 4;
	}
	if (token == "==" || token == "!=") {
		return 3;
	}
	if (token == "&&") {
		return 2;
	}
	if (token == "||") {
		return 1;
	}
	if (token == "(" || token == "[") {
		return 0;
	}
	else return -1;
}

string convert_output(int q_size, Queue q) // Converts the Queue nodes into a string and checks for expression validity 
{
	string result;
	Node* NextNode;
	while (q_size != 0) {
		NextNode = q.dequeue();
		if (isparenth(NextNode->data))
			return "INVALID";

		result.append(NextNode->data);
		q_size--;
	}
	return result;
}

