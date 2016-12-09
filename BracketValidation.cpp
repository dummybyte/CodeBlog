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
// using STL stack
stack<char> st;

bool checkStringValidity(string str) {
    int i;
    FOR(i,0,str.size()) {
        if(str[i] == '(') {
            //push it to stack
            st.push(str[i]);
        } else {
            // pop from the stack
            st.pop();
        }
    }
    if(st.empty()) {
        return true;
    } else {
        return false;
    }
}
int main() {
    string str;
    cin>>str;
    if(checkStringValidity(str)) {
        cout<<"Valid"<<"\n";
    } else {
        cout<<"Invalid"<<"\n";
    }
}