    #include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* invertTree(TreeNode* root) {
        if(root==NULL) return NULL;
        if(root->left) invertTree(root->left);
        if(root->right) invertTree(root->right);
        TreeNode* temp=root->left;
        root->left=root->right;
        root->right=temp;
        
        return root;
}