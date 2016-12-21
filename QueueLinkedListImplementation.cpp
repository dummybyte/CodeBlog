#include <iostream>
#include <vector>

using namespace std;

// Queue is represented by this struct

struct Queue {
   int data;
   struct Queue *next;
};

struct Queue *front, *rear;

void initialize() {
   front = NULL;
   rear = NULL;
}
void push(int element) {
    //push the element into the Queue
    Queue *node;
    //if queue is empty
    if(front == NULL && rear == NULL) {
       node  = new Queue();
       node->data = element;
       node->next = NULL;
       front = node;
       rear = node;
    } else {
       node = new Queue();
       node->data = element;
       rear->next = node;
       rear = rear->next;
       node->next = NULL;
    }
}
int pop() {
   //initialising the element to some value
   int element = INT_MAX;
   // check if Queue is not empty
   if(front != NULL) {
       //fetch the start element - this element must have come in Queue the first
       element = front->data;
       //point to the next first element
       front = front->next;
    }
    return element;
}
int main() {
    initialize();
    push(10);
    push(20);
    push(30);
    cout<<pop()<<"\n";
    push(40);
    cout<<pop()<<"\n";
    return 0;

}
