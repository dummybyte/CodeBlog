#include <iostream>
#include <vector>

using namespace std;

// queue is represented by this vector

vector<int> Queue;
int front  = -1;
void push(int element) {
    //push the element into the queue
    Queue.push_back(element);
     if(front == -1) {
          front++;
      }
}
int pop() {
   //initialising the element to some value
   int element = INT_MAX;
      // check if queue is not empty
    if(front != -1) {
      //fetch the start element - this element must have come in queue the first
     element = Queue[front];
      //point to the next first element
     front++;
      //this is to find out when Queue is empty
      if(front >= Queue.size()) {
          front = -1;
      }
   }
   return element;
}
int main() {
  push(10);
  push(20);
  push(30);
  cout<<pop()<<"\n";
  push(40);
  cout<<pop()<<"\n";
    return 0;
}
