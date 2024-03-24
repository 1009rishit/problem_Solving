#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void solve(TreeNode* root,int targetSum,vector<vector<int>> &path,vector<int> sum){
        if(root==NULL) return;
        sum.push_back(root->val);
        targetSum-=root->val;
        if(root->left==NULL && root->right==NULL &&targetSum==0)
        path.push_back(sum);
        solve(root->left,targetSum,path,sum);
        solve(root->right,targetSum,path,sum);
        
}
vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> path;
        vector<int> sum;
        if(root==NULL){
        return path;
    }
        solve(root,targetSum,path,sum);
        return path;
}