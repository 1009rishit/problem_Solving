#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};   
    void solve(TreeNode* root, TreeNode* first,TreeNode*last,TreeNode*prev){
        if(root==NULL) return;
        solve(root->left,first,last,prev);
        if(first == NULL && prev != NULL && prev->val >= root->val)
            first=prev;
        if(first!=NULL && root->val <= prev->val){
            last=root;
        }
        prev=root;
        solve(root->right,first,last,prev);
    }
    void recoverTree(TreeNode* root) {
        TreeNode* first,*last,*prev;
        first=last=prev=NULL;
        solve(root,first,last,prev);
        swap(first->val,last->val);
        return;
    }