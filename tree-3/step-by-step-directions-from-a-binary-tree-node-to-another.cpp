#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
bool find(TreeNode* n, int val, string &path) {
    if (n->val == val)
        return true;
    if (n->left && find(n->left, val, path))
        path.push_back('L');
    else if (n->right && find(n->right, val, path))
        path.push_back('R');
    if(path.empty())return false;
    return true;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
     string a,b;
     find(root,startValue,a);
     find(root,destValue,b); 
     while(!a.empty() && !b.empty() && a.back()==b.back()){
        a.pop_back();
        b.pop_back();
     }
     string s;
     if(a.size()>0){
     for(auto it:a) s+='U';
     }
    reverse(b.begin(),b.end());
     string ans=s+b;
     return ans;
    }
