#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
bool solve(TreeNode* A, int B,vector<int>& ans){
    if(A==NULL) return false;
    if(A->val==B || solve(A->left,B,ans) || solve(A->right,B,ans)) {
        ans.push_back(A->val);
        return true;
    }
    return false;
}
vector<int> Solutionsolve(TreeNode* A, int B) {
    vector<int> ans;
    solve(A,B,ans);
    reverse(ans.begin(),ans.end());
    return ans;
}