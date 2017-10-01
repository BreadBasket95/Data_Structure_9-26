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

#include "Node.h"
#include "Stack.h"
#include "Queue.h"

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
