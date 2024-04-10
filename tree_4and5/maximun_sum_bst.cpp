#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};  
int ans=INT_MIN;
class nodeinfo {
public:
    bool isBST;
    int min_element;
    int max_element;
    int sum;
    
    nodeinfo() : isBST(true), min_element(INT_MAX), max_element(INT_MIN), sum(0) {}
    nodeinfo(bool isBST, int min_element, int max_element, int sum)
        : isBST(isBST), min_element(min_element), max_element(max_element), sum(sum) {}
};
class Solution {
public:
    nodeinfo solve(TreeNode *root){
        if(root == NULL){
            return nodeinfo();
        }
        
        nodeinfo left = solve(root->left);
        nodeinfo right = solve(root->right);
        
        nodeinfo newroot;
        newroot.min_element = min(left.min_element, min(right.min_element, root->val));
        newroot.max_element = max(right.max_element, max(left.max_element, root->val));
        
        if(left.isBST && right.isBST && root->val > left.max_element && root->val < right.min_element) {
            newroot.isBST = true;
            newroot.sum = left.sum + right.sum + root->val;
        } else {
            newroot.isBST = false;
            newroot.sum = max(left.sum, right.sum);
        } 
        ans=max(ans,newroot.sum);
        return newroot;
    }
    int maxSumBST(TreeNode* root) {
        ans=0;
        solve(root);
        return ans;
    }
};