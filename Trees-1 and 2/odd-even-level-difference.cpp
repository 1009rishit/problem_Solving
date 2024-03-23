#include<bits/stdc++.h>
using namespace std;
struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};
int getLevelDiff(Node *root)
{
    if(root==NULL) return 0;
    return root->val - getLevelDiff(root->left) - getLevelDiff(root->right);
}