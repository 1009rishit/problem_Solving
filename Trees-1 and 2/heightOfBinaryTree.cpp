#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int heightOfBinaryTree(TreeNode *root)
{
   if(root==NULL) return 0;
   return max(heightOfBinaryTree(root->left),heightOfBinaryTree(root->right))+1;
}