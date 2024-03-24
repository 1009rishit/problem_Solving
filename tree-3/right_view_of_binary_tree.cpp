#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void solve(TreeNode* root,vector<int> &ans,int level){
    if(root==NULL) return;
    if(level==ans.size()) ans.push_back(root->val);
    solve(root->right,ans,level+1);
    solve(root->left,ans,level+1);
}
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        solve(root,ans,0);
        return ans;
        
    }