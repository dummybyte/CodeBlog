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
//create loop in the linked list
void createLoop(node *head) {
    node *tmp = head, *dummy;
    int cnt = 0;
    while(tmp->next != NULL) {
        tmp = tmp->next;
        cnt++;
        if(cnt == 5) {
            dummy = tmp;
        }
    }
    tmp->next = dummy;
}
//method to detect loop in the linked list
bool isLoopPresent(node *head) {
    //if only 1 node is present
    if(head -> next == NULL) {
        return false;
    }
    node *ptr1 = head->next,*ptr2 = head->next->next;
    while(ptr1 != ptr2 && ptr1 != NULL && ptr2 != NULL) {
        // if there is loop then none of the pointers will be none
        if(ptr1->next == NULL || ptr2->next->next == NULL) {
            return false;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next->next;
    }
    if(ptr1 == ptr2 && ptr1 != NULL) {
        return true;
    }
    return false;
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
    createLoop(head);
    if(isLoopPresent(head)) {
        cout<<"YES\n";
    } else {
        cout<<"NO\n";
    }

    return 0;
}
