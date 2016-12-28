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
queue<int> Q1, Q2;
// push method for Q1
void push(int x) {
    Q1.push(x);
}
int pop() {
    int top = -1, output = -1;
    // keep on popping till Q1 is empty
    while(!Q1.empty()) {
        top = Q1.front();
        Q1.pop();
        // after each pop check if Q1 is empty
        if(Q1.empty()) {
            //This is our popped element if our DS was a Stack
            output = top;
            break;
        }
        // store the popped element to a tmp Queue
        Q2.push(top);
    }
    // Transfer the elements from Q2 to Q1
    while(!Q2.empty()) {
        top = Q2.front();
        Q2.pop();
        Q1.push(top);
    }
    return output;
}
int main() {
    push(1);
    push(2);
    push(3);
    cout<<pop()<<"\n";
    push(4);
    push(5);
    push(6);
    cout<<pop()<<"\n";
}
