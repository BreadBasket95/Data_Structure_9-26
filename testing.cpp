#include <iostream>
#include <string>
using namespace std;
#include "Node.h"
#include "Stack.h"
#include "Queue.h"
#include "Queue.cpp"




int main()
{
 Queue testqueue;
 int e1 = 1, e2=2, e3=3, e4=4, e5=5, e6=6;
 string c1= "a", c2="b", c3="c", c4="d", c5="e", c6="f";

  testqueue.enqueue(c1, e1);
  testqueue.enqueue(c2, e2);
  testqueue.enqueue(c3, e3);
  testqueue.enqueue(c4, e4);
  testqueue.enqueue(c5, e5);
  testqueue.enqueue(c6, e6);
for(int c = 0; c < 6; c++)
{
  Node *tempnode = new Node;
  tempnode = testqueue.dequeue();
  cout << tempnode->data << " and " << tempnode->precedence;
}
return 0;
}
