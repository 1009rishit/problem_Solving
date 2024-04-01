#include<bits/stdc++.h>
using namespace std;
struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};  
void solve(Node* root, int key ,int& ans){
        if(root==NULL) return;
        if(root->val>=key && root->val<ans){
            ans=root->val;
        }
        solve(root->left,key,ans);
        solve(root->right,key,ans);
}
int findCeil(Node* root, int input) {
    if (root == NULL) return -1;
    int ans=INT_MAX;
    solve(root,input,ans);
    return ans==INT_MAX?-1:ans;
}