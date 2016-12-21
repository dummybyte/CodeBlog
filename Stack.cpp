#include <iostream>
#include <vector>

using namespace std;

// stack is represented by this vector
vector <int> Stack;
// this represents top of the stack - basically the index of the top element in the stack
int top = -1;

void push(int element) {
   //push the element into the stack
   Stack.push_back(element);
   // update the top variable
   top++;
}
int pop() {
   // store the element at the top of the stack
   int element;
   if(!Stack.empty()) {  //check if the stack is not empty
    element = Stack[top];
    //delete the last element from the vector :: vector deletion of last element takes O(1) time
    Stack.erase(Stack.begin() + top);
    // update the top
    top--;
   } else {
    element = INT_MAX; //return some value to recognize if stack is empty
   }

   // return the popped element
   return element;
}
int main() {
   push(10);
   push(20);
   push(30);
   cout<<pop()<<"\n";
   cout<<pop()<<"\n";
   return 0;
}
