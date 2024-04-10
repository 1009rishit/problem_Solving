#include<bits/stdc++.h>
using namespace std;
class TrieNode{
    public:
    TrieNode* children[26];
    bool terminal;
    TrieNode(){
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        terminal=false;
    }
};
class Solution {
 TrieNode* root;
public:
     void insert(string word) {
        TrieNode *p=root;
        for(int i=0;i<word.length();i++){
            char ch=word[i];
            if(p->children[ch-'a']==NULL){
            p->children[ch-'a']=new TrieNode();
            }
            p=p->children[ch-'a'];
        }
        p->terminal=true;
    }
string search(string word){
        TrieNode *p=root;
        string s="";
        for(int i=0;i<word.length();i++){
            char ch=word[i];
            if(!p->children[ch-'a']) break;
            s+=ch;
            p=p->children[ch-'a'];
            if(p->terminal) return s;
        }
        
        return word;
    }
    string replaceWords(vector<string>& dict, string sentence) {
        root = new TrieNode();
        for(auto s : dict) insert(s);
        istringstream ss(sentence);
        string word = "", ans="";
        
        for(; ss>>word; ){
            ans += search(word);
            ans += ' ';
        }
        ans.pop_back();
        
        return ans;
    }
};