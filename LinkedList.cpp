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

struct node {
    int num;
    node *next;
};

node *head = new node();

bool search(int n) {
    node *tmpHead = head;
    while(tmpHead != NULL && tmpHead->num != n) {
        tmpHead = tmpHead->next;
    }
    if(!tmpHead) {
        return false;
    }
    return true;
}

void insert(int x) {
    node *tmpHead = head;
    while(tmpHead->next != NULL) {
        tmpHead = tmpHead->next;
    }
    node *tmp = new node();
    tmp->num = x;
    tmp->next = NULL;
    tmpHead->next = tmp;
}

void del(int n) {
    node *tmpHead = head;
    while(tmpHead->next != NULL && tmpHead->next->num != n) {
        tmpHead = tmpHead->next;
    }
    if (!search(n)) {
        cout << "element not found";
        return;
    }
    node *temp = tmpHead->next;
    tmpHead->next = temp->next;
    delete(temp);
}


int main() {

    insert(1);
    insert(2);
    insert(3);

    cout<<search(3)<<"\n";
    del(3);
    cout<<search(3)<<"\n";
    return 0;
}
