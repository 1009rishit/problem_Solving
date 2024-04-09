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
class Trie {
    TrieNode* root;
public:
    Trie() {
       root = new TrieNode(); 
    }  
    void insert(string word) {
        TrieNode *p=root;
        for(auto &a:word){
            int i=a-'a';
            if(!p->children[i]) p->children[i]=new TrieNode();
            p=p->children[i];
        }
        p->terminal=true;
    }
    
    bool search(string word,bool prefix=false){
        TrieNode *p=root;
        for(auto &a:word){
            int i=a-'a';
            if(!p->children[i]) return false;
            p=p->children[i];
        }
        if(prefix==false) return p->terminal;
        return true;
    }
    
    bool startsWith(string prefix) {
        return search(prefix,true);
    }
};

