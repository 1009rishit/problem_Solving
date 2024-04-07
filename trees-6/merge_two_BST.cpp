    #include<bits/stdc++.h>
    using namespace std;
    struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};   
    void inorder(Node *root,vector<int>& ans){
        if(root==NULL) return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    vector<int> merge(Node *root1, Node *root2)
    {
    vector<int> ans1,ans2;
    inorder(root1,ans1);
    inorder(root2,ans2);
    int i=0,j=0;
    vector<int> result;
    while(i<ans1.size() && j<ans2.size()){
        if(ans1[i] < ans2[j]) {
            result.push_back(ans1[i]);
            i++;
        }
        else {
            result.push_back(ans2[j]);
            j++;
        }
    }
     while(i<ans1.size()){
        result.push_back(ans1[i]);
        i++;
     }
     while(j<ans2.size()){
        result.push_back(ans2[j]);
        j++;
     }
     return result;
    }