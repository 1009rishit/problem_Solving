#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 int findBottomLeftValue(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return NULL;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int s=q.size();
            vector<int> res;
            for(int i=0;i<s;i++){
             TreeNode *node=q.front();
             q.pop();
             if(node->left!=NULL) q.push(node->left);
             if(node->right!=NULL) q.push(node->right);
             res.push_back(node->val);
            }
            ans.push_back(res);
        }
        return ans[ans.size()-1][0];
    }