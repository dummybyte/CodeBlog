/*
Author :  ARVIND PANDEY
 */
#include <iostream>
#include <stdio.h>
#include <climits>
#include <cstring>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>

using namespace std;
struct _ {
    ios_base::Init i;

    _() {
        cin.sync_with_stdio(0);
        cin.tie(0);
    }
} _;

#define FOR(i,a,b) for(i=a;i<b;i++)
#define pb(x) push_back(x)
#define ll long long
#define mp make_pair

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<vii> vvii;

ll power(ll a, ll n, ll p) //////             O(log n)
{
    ll ans = 1;
    while (n) {
        if (n % 2 == 1)
            ans =(ans * a) % p;
        a = (a * a) % p;
        n /= 2;
    }
    return ans % p;
}

ll gcd(ll a, ll b) ////                 O(log(a+b))
{
    if (b==0)
        return a;
    return gcd(b,a%b);
}
////////////////////////////////////////////////////////////////////////////////////CODE BEGINS/////////////////////////////////////////////////////////
/* this struct represents a linked list
* the num represents the data stored in the linked list and
* the *next pointer is the pointer to the next node in the linked list
*/
struct node {
    int num;
    node *next;
    node *rnd;
};

// declaring head
node *head;
// to insert a element in the linked list
void insert(int x) {
    if(head == NULL) {
        head = new node();
        head->next = NULL;
        head->num = x;
        return;
    }
    node *tmpHead = head;

    while(tmpHead->next != NULL) {
        tmpHead = tmpHead->next;
    }
    // now we have reached at the end of the linked list
    node *tmp = new node();
    tmp->num = x;
    tmp->next = NULL;
    //point the previous end of linked list to current node
    tmpHead->next = tmp;
}
/* This method is just for the creating a linked list with random ptr
you can write your own method
*/
void configureRandomPtr() {
    node *tmpHead = head;
    while(tmpHead->next->next != NULL) {
        tmpHead->rnd = tmpHead->next->next;
        tmpHead = tmpHead->next->next;
    }
    tmpHead->rnd = tmpHead->next;
    tmpHead->next->rnd = tmpHead;
}

//This method add nodes in between the nodes of the existing linked list
void addNodesInBetween(node *head) {
    node *tmpHead = head, *tmp;
    //insert an element between each of the two nodes
    while(tmpHead->next != NULL) {
        tmp = new node();
        tmp->num = tmpHead->num;
        tmp->next = tmpHead->next;
        tmpHead->next = tmp;
        tmpHead = tmpHead->next->next;
    }
    //adding the last node
    tmp = new node();
    tmp->next = NULL;
    tmp->num = tmpHead->num;
    tmpHead->next = tmp;
}

//final clone :: here we will also make changes for the random ptr
node* clone(node *head) {
    node *newHead = head->next, *tmpHead = head, *finalHead = head->next;
    while(tmpHead != NULL) {
        if(tmpHead->rnd != NULL) {
            newHead->rnd = tmpHead->rnd->next;
        }
        tmpHead = tmpHead->next->next;
        if(newHead->next != NULL) {
            newHead = newHead->next->next;
        }
    }
    newHead = head->next;
    while(newHead->next != NULL) {
        newHead->next = newHead->next->next;
        newHead = newHead->next;
    }
    return finalHead;
}

void printLinkedList(node *head) {
    while(head != NULL) {
        cout<<head->num<<" ";
        head = head->next;
    }
    cout<<"\n";
}

int main() {
    insert(1);
    insert(2);
    insert(3);
    insert(5);
    insert(6);
    insert(7);
    insert(8);
    insert(9);
    configureRandomPtr();
    printLinkedList(head);
    addNodesInBetween(head);
    printLinkedList(head);
    node *tmpHead = clone(head);
    printLinkedList(tmpHead);
    return 0;
}
