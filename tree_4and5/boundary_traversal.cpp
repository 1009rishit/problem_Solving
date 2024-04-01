#include<bits/stdc++.h>
using namespace std;
struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};  
void left_solve(Node *root,vector<int>& ans){
    if(root==NULL ||( root->left==NULL && root->right==NULL)) return;
    ans.push_back(root->val);
    if(root->left) left_solve(root->left ,ans);
    else left_solve(root->right,ans);
}
void leaf_solve(Node *root,vector<int>& ans){
        if (root==NULL) return;
        if (root->left == NULL && root->right == NULL) {
          ans.push_back(root->val);
          return;
        }
        leaf_solve(root->left,ans);
        leaf_solve(root->right, ans);
}

void leaf_right(Node *root,vector<int>& ans){
    if(root==NULL || ( root->left==NULL && root->right==NULL)) return;
    if(root->right) leaf_right(root->right ,ans);
    else leaf_right(root->left,ans);
     ans.push_back(root->val);
}
vector<int> traverseBoundary(Node *root)
{
	vector<int> ans;
    ans.push_back(root->val);
    left_solve(root->left,ans);
    leaf_solve(root,ans);
    leaf_right(root->right,ans);
    return ans;
}