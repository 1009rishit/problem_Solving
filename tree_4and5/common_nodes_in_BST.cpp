#include<bits/stdc++.h>
using namespace std;
struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};  
    void solve(Node *root, set<int>& ans){
        if(root==NULL) return;
        ans.insert(root->val);
        solve(root->left,ans);
        solve(root->right,ans);
    }
    vector <int> findCommon(Node *root1, Node *root2)
    {
      set<int> set1,set2;
      solve(root1,set1);
      solve(root2,set2);
      vector<int> ans;
      for(auto it:set1){
          if(set2.count(it)) ans.push_back(it);
      }
      return ans;
    }