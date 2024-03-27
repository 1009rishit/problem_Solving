#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
    void str(TreeNode* root,string& ans){
        if(root==NULL){
            ans+="*,";
            return;
        }
        ans+=to_string(root->val)+",";
        str(root->left,ans);
        str(root->right,ans);
    }
    string serialize(TreeNode* root) {
        string ans="";
        str(root,ans);
        return ans;
    }

   TreeNode* trees(queue<string>& q){
        string s=q.front();
        q.pop();
        if(s=="*") return NULL;
        TreeNode* root=new TreeNode(stoi(s));
        root->left=trees(q);
        root->right=trees(q);
        return root;
     }
    TreeNode* deserialize(string data) {
        string s="";
        queue<string> q;
        for(char ch:data){
            if(ch==','){
                q.push(s);
                s="";
            }
            else
            s+=ch;
        }
        return trees(q);
    }