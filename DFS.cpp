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

//denote tree using vector of vectors
vector<int> tree[10];

void dfs(int node) {
    int i;
    // print the current node
    cout<<node<<"\n";
    // traverse over the child of the current node and call dfs() on its child
    FOR(i,0,tree[node].size()) {
        dfs(tree[node][i]);
    }
}
void constructSampleTree() {
    tree[1].pb(2);
    tree[1].pb(3);
    tree[2].pb(4);
    tree[2].pb(5);
    tree[3].pb(6);
    tree[3].pb(7);
}

int main() {
    constructSampleTree();
    // pass the root node to dfs()
    dfs(1);
}
