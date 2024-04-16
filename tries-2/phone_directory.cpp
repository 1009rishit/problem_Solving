#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    char ch;
    bool isend;
    vector<Node*> next;
    
    Node(char c) {
        ch = c;
        isend = false;
        next.resize(26, NULL);
    }
};
class Solution{
public:
 void rec(Node *root, vector<string> &res, string cur) {
        if (root) {
            if (root->isend)
                res.push_back(cur + root->ch);
            for (int j = 0; j < 26; j++) {
                if (root->next[j] != NULL)
                    rec(root->next[j], res, cur + root->ch);
            }
        }
    }
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        vector<vector<string>> res(s.size());
        Node *root = new Node(s[0]);
        char start = s[0];
        for (int i = 0; i < n; i++) {
            string ts = contact[i];
            if (ts[0] == start) {
                Node *temp = root;
                for (int j = 1; j < contact[i].length(); j++) {
                    if (temp->next[(int)ts[j] - 'a'] == NULL) {
                        temp->next[(int)ts[j] - 'a'] = new Node(ts[j]);
                    }
                    temp = temp->next[(int)ts[j] - 'a'];
                }
                temp->isend = true;
            }
        }
        Node *temp = root;
        string cur = "";
        for(int i = 0; i < s.size(); i++) {
            if (i != 0)
                temp = temp->next[(int)s[i] - 'a'];
            rec(temp, res[i], cur);
            if (res[i].empty() || temp == NULL) {
                for (; i < s.size(); i++) {
                    res[i].push_back("0");
                }
                break;
            }
            cur += temp->ch;
        }
        return res;
    }
};