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
stack<int> S1, S2;
// push method for S1
void push(int x) {
    S1.push(x);
}
int pop() {
    int top = -1, output = -1;
    // keep on popping till S1 is empty
    while(!S1.empty()) {
        top = S1.top();
        S1.pop();
        // store the popped element to a tmp Queue
        S2.push(top);
    }
    output = S2.top();
    S2.pop();
    // Transfer the elements from S2 to S1
    while(!S2.empty()) {
        top = S2.top();
        S2.pop();
        S1.push(top);
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
