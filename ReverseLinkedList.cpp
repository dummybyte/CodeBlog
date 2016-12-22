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
};

// initialising head to new node
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

node* reverse(node *head) {
    //case when there is only one node or no node
    if(head->next == NULL || head == NULL) {
        return head;
    }
    // if there are only two elements
    else if(head->next->next == NULL) {
        node *newHead = head->next;
        head->next = NULL;
        newHead->next = head;
        return newHead;
    }
    // declare 3 pointers denoting current, previous and newHead of the reverse linked list
    node *current, *previous, *newHead;
    previous = head;
    current = head->next;
    newHead = head->next->next;
    // each time we will be reversing current and previous nodes
    while(newHead != NULL) {
        if(previous == head) {
            previous->next = NULL;
        }
        current->next = previous;
        previous = current;
        current = newHead;
        newHead = newHead->next;
    }
    current->next = previous;
    return current;
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
    insert(4);
    printLinkedList(head);
    node *newHead = reverse(head);
    printLinkedList(newHead);
    return 0;
}
