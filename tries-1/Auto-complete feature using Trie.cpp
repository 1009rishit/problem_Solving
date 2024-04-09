#include<bits/stdc++.h>
using namespace std;
class TrieNode{
    public:
    TrieNode* children[26];
    bool terminal;
    vector<string> prefix;
    TrieNode(){
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        terminal=false;
        vector<string> prefix;
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
            p->prefix.push_back(word);
        }
        p->terminal=true;
    }
 vector<string> search(string word){
        TrieNode *p=root;
        for(int i=0;i<word.length();i++){
            char ch=word[i];
            if(p->children[ch-'a']==NULL) return {};
            p=p->children[ch-'a'];
        }
        
        return p->prefix;
    }
int main(){
    struct TrieNode* root = new TrieNode();
    insert("hello");
    insert("dog");
    insert("hell");
    insert("cat");
    insert("a");
    insert("hel");
    insert("help");
    insert("helps");
    insert("helping");
    vector<string> ans;
    ans=search("hel");
    for(auto it:ans)
     cout<<it;

}
};