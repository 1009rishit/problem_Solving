#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};   
    void inorder(TreeNode* &root,int k,int& ans,int count){
        if(root==NULL) return ;
         inorder(root->left,k,ans);
        count++;
        if(count==k) {
            ans=root->val;
            return;
        }
        inorder(root->right,k,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        inorder(root,k,ans,0);
        return ans;
     }