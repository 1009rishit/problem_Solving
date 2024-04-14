#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
struct TrieNode 
{
    int count;
    struct TrieNode *left, *right;  
};
void insert( TrieNode* root,int val){
    for(int i=14; i>=0; i--){
        int bit=(1<<i)&val;
        if(bit==0){
            if(root->left==NULL){
                root->left=new TrieNode();
            }
                root=root->left;
        }
        else{
            if(root->right==NULL){
                root->right=new TrieNode();   
            }
                root=root->right;
        }
        root->count++;
    }
}
int getcnt(TrieNode* root){
    if(root==NULL){
        return 0;
    }
    return root->count;
}
int query(TrieNode* root, int num, int k, int index){
    if(root==NULL){
        return 0;
    }
    if(index==-1){
        return getcnt(root);
    }
    int value=((1<<index)&num)>0?1:0;
    int kth=((1<<index)&k)>0?1:0;
     if(value==0){
        if(kth==0){
             return query(root->left, num, k, index-1);
        }
        else{
            return getcnt(root->left)+query(root->right, num, k, index-1);
        }
    }
    else{
        if(kth==0){
             return query(root->right, num, k, index-1);
        }
        else{
            return query(root->left, num, k, index-1)+getcnt(root->right);
        }
    }
}
int countPairs(vector<int>& nums, int low, int high) {
    TrieNode *node=new TrieNode();
    int MaxBit=14;
    int cnt=0;
    int n=nums.size();
    for(int i=0; i<n; i++){
        cnt+=query(node,nums[i],high, MaxBit);
        cnt-=query(node,nums[i], low-1, MaxBit);  
        insert(node , nums[i]);
        }
        return cnt;
    } 
};