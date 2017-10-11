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
#include "Queue.h"


using namespace std;

int get_precedence(string token);
string convert_to_pf(string eq);
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
	/*
	// invalid equation check
	cout << convert_to_pf("2*(2-7]/4") << endl;
	cout << convert_to_pf("[2*(2-7)/4") << endl;
	cout << convert_to_pf("[2*(2-7)/(4") << endl;
	cout << convert_to_pf(")2*(2-7)/(4") << endl;
	*/

	cout << "******************************************\n\n";

}

string convert_to_pf(string eq)
{
	cout << eq << ": ";
	Stack s;
	Queue q;
	int q_size = 0;

	for (unsigned int index = 0; index < eq.length(); index++)
	{
		string character;
		bool is_digit = isdigit(eq[index]);
		if (get_precedence(eq.substr(index, 2)) > 0) {
			character = eq.substr(index, 2);
		}
		else {
			character = eq.substr(index, 1);
		}
		
		int precedence;

		if (!is_digit) {
			precedence = get_precedence(character);
		}

		if (is_digit) {
			q.enqueue(character, -1);
			q_size++;
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

		else if (character == ")" ){
			while (s.top()->data != "(")
			{
				q.enqueue(s.pop());
				q_size++;
			}
			if (s.top()->data == "(") {
				s.pop();
			}
		}

	}
	while (s.top()) {
		q.enqueue(s.pop());
		q_size++;
	}

	cout << "result: ";
	Node* NextNode;
	while(q_size != 0) {
		NextNode = q.dequeue();
		cout << NextNode->data;
		q_size--;
	}

	return "";

}


int get_precedence(string token) {

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


