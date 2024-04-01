#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};  
vector<int> element(TreeNode* root, int low, int high,vector<int> &ans){
        if(root==NULL) return ans;
        if(root->val>=low && root->val<=high) ans.push_back(root->val);
        if(root->left!=NULL) element(root->left,low, high, ans);
        if(root->right!=NULL) element(root->right,low, high, ans);
        return ans;
    }
int rangeSumBST(TreeNode* root, int low, int high) {
        vector<int> ans;
        element( root, low, high, ans);
        int sum=0;
         for(int i=0;i<ans.size();i++){
             sum+=ans[i];
         }
         return sum;
}