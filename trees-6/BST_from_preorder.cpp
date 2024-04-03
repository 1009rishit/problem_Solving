#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}; 
TreeNode* solve(vector<int>& preorder,int mini,int maxi,int &i){
         if(i>=preorder.size()) return NULL;
         if(preorder[i]<=mini || preorder[i]>=maxi) return NULL;
        TreeNode* root= new TreeNode(preorder[i++]);
        root->left=solve(preorder,mini,root->val,i);
        root->right=solve(preorder,root->val,maxi,i);
        return root;
             }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int mini=INT_MIN;
        int maxi=INT_MAX;
        int i=0;
        return solve(preorder,mini,maxi,i);
    }