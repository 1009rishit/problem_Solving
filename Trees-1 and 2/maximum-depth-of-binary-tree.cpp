#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int left=maxDepth(root->left);
        int right=maxDepth(root->right);
        int ans=max(left,right)+1;
        return ans;
}