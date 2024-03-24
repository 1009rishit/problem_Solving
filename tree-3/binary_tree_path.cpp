#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 void solve(vector<string>& ans, TreeNode* root, string t) {
    if(!root->left && !root->right) {
        ans.push_back(t);
        return;
    }

    if(root->left) solve(ans, root->left, t + "->" + to_string(root->left->val));
    if(root->right) solve(ans, root->right, t + "->" + to_string(root->right->val));
}
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        solve(ans,root,to_string(root->val));
        return ans;

    }