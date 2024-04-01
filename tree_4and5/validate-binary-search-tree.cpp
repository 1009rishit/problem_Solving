#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
    bool solve(TreeNode* root,long long a,long long b){
        if(!root) return true;
        if(a && root->val>=b || b && root->val<=a) return false;
        return solve(root->left,a,root->val) && solve(root->right,root->val,b);
    }
    bool isValidBST(TreeNode* root) {
        return solve(root,LLONG_MIN,LLONG_MAX);
    }