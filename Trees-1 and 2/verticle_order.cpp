    #include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>node;

        queue<pair<TreeNode*,pair<int ,int>>> q;

        vector<vector<int>> ans;
        if(root==NULL) return ans;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto temp=q.front();
            TreeNode* frontnode=temp.first;
            q.pop();
            int hd=temp.second.first;
            int lvl=temp.second.second;
            node[hd][lvl].insert(frontnode->val);
            if(frontnode->left) 
            q.push({frontnode->left,{hd-1,lvl+1}});
            if(frontnode->right)
            q.push({frontnode->right,{hd+1,lvl+1}});
        }
        for(auto i:node){
             vector<int> temp;
            for(auto it: i.second){
                temp.insert(temp.end(),it.second.begin(),it.second.end());
                }
            ans.push_back(temp);
        }
        return ans;
    }