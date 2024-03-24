#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void left_view(TreeNode* root,int level,vector<int>& ans){
    if(root==NULL) return;
    if(ans.size()>level){
        ans.push_back(root->val);
    }
    left_view(root->left,level+1,ans);
    left_view(root->right,level+1,ans);
}
vector<int> printLeftView(TreeNode* root) {
        vector<int> ans;
        left_view(root,0,ans);
        for(auto it:ans) cout<<it;
        return ans;
}