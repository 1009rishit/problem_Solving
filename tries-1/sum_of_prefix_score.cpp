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
        for(int i=0;i<word.length();i++){
            char ch=word[i];
            if(p->children[ch-'a']==NULL){
            p->children[ch-'a']=new TrieNode();
            }
            p=p->children[ch-'a'];
        }
        p->terminal=true;
    }
    
    bool search(string word){
        TrieNode *p=root;
        for(int i=0;i<word.length();i++){
            char ch=word[i];
            if(p->children[ch-'a']==NULL) return false;
            p=p->children[ch-'a'];
        }
        if(p->terminal) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode *p=root;
        for(int i=0;i<prefix.length();i++){
            char ch=prefix[i];
            if(p->children[ch-'a']==NULL) return false;
            p=p->children[ch-'a'];
        }
        return true;
    }
};