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

//denote tree using struct
struct tree {
    int data;
    tree *left;
    tree *right;
};

void inorder(tree *root) {
    //traverse the left subtree
    if(root ->left != NULL) {
        inorder(root->left);
    }
    // traverse the root
    if(root != NULL) {
        cout<<root->data<<" ";
    }
    //traverse the right subtree
    if(root->right != NULL) {
        inorder(root->right);
    }
}

void preorder(tree *root) {
    // traverse the root
    if(root != NULL) {
        cout<<root->data<<" ";
    }
    //traverse the left subtree
    if(root ->left != NULL) {
        preorder(root->left);
    }
    //traverse the right subtree
    if(root->right != NULL) {
        preorder(root->right);
    }   
}

void postorder(tree *root) {
    //traverse the left subtree
    if(root ->left != NULL) {
        postorder(root->left);
    }
    //traverse the right subtree
    if(root->right != NULL) {
        postorder(root->right);
    }
    // traverse the root
    if(root != NULL) {
        cout<<root->data<<" ";
    }
}
//manual construction of the tree
tree* constructSampleTree() {
    tree *root = new tree();
    root->data = 1;
    tree *lft = new tree();
    lft->data = 2;
    root->left = lft;
    tree *rt = new tree();
    rt->data = 3;
    root->right = rt;
    
    tree *lft2 = new tree();
    lft2->data = 4;
    lft2->left = NULL;
    lft2->right = NULL;
    lft->left = lft2;
    tree *lft3 = new tree();
    lft3->data = 5;
    lft3->left = NULL;
    lft3->right = NULL;
    lft->right = lft3;
    
    tree *rt2 = new tree();
    rt2->data = 6;
    rt2->left = NULL;
    rt2->right = NULL;
    rt->left = rt2;
    tree *rt3 = new tree();
    rt3->data = 7;
    rt3->left = NULL;
    rt3->right = NULL;
    rt->right = rt3;
    return root;
}

int main() {
    tree *root = constructSampleTree();
    cout<<"Inorder Traversal: \n";
    inorder(root);
    cout<<"\nPreorderTraversal: \n";
    preorder(root);
    cout<<"\nPostorder Traversal: \n";
    postorder(root);
}
