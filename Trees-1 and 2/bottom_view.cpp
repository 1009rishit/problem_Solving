    #include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left, *right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};
vector <int> bottomView(Node *root) {
        vector<int> ans;
        queue<pair<Node*, int>> q;
        map<int,int> map1;
        if(root==NULL) return ans;
        q.push({root,0});
        while(!q.empty()){
            auto it=q.front();
            Node* line=it.first;
            int l=it.second;
            q.pop();
            map1[l]=line->data;
            if(line->left!=NULL) q.push({line->left,l-1});
            if(line->right!=NULL) q.push({line->right,l+1});
        }
        for(auto it:map1)
        ans.push_back(it.second);
        return ans;
    }