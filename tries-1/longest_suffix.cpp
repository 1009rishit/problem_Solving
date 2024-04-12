#include<bits/stdc++.h>
using namespace std;
class TrieNode{
    public:
    TrieNode* children[26];
    int ind;
    TrieNode(int indx){
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        ind=indx;
    }
};
class Solution {
public:
    void add(TrieNode* ptr, vector<string>& wordsContainer, int i){
        for(int j = wordsContainer[i].size() - 1; j >= 0; --j){
            int c = wordsContainer[i][j] - 'a';
            if(ptr->children[c] == NULL) ptr->children[c] = new TrieNode(i);
            ptr = ptr->children[c]; 
            if(wordsContainer[ptr->ind].size() > wordsContainer[i].size()) ptr->ind = i;
        }
    }
        int search(TrieNode* ptr, string &s){
        int ans = ptr->ind;
        for(int i = s.size()-1; i >= 0; --i){
            ptr = ptr->children[s[i] - 'a'];
            if(!ptr) return ans;
            ans = ptr->ind;
        }
        return ans;
    }
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        vector<int> ans;
        TrieNode* head = new TrieNode(0);
        for(int i = 0; i < wordsContainer.size(); ++i) {
            if(wordsContainer[head->ind].size() > wordsContainer[i].size()) head->ind = i;
            add(head, wordsContainer, i);
        }
        for(auto q: wordsQuery) ans.push_back(search(head, q));
        return ans;
    }
};