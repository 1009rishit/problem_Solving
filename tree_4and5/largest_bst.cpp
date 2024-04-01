#include<bits/stdc++.h>
using namespace std;
struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
}; 
class nodeinfo {
public:
    bool isBST;
    int min_element;
    int max_element;
    int size;
    
    nodeinfo() : isBST(true), min_element(INT_MAX), max_element(INT_MIN), size(0) {}
    nodeinfo(bool isBST, int min_element, int max_element, int size)
        : isBST(isBST), min_element(min_element), max_element(max_element), size(size) {}
};

    nodeinfo solve(Node *root){
        if(root == NULL){
            return nodeinfo();
        }
        
        nodeinfo left = solve(root->left);
        nodeinfo right = solve(root->right);
        
        nodeinfo newroot;
        newroot.min_element = min(left.min_element, min(right.min_element, root->val));
        newroot.max_element = max(right.max_element, max(left.max_element, root->val));
        
        if(left.isBST && right.isBST && root->val > left.max_element && root->val < right.min_element) {
            newroot.isBST = true;
            newroot.size = left.size + right.size + 1;
        } else {
            newroot.isBST = false;
            newroot.size = max(left.size, right.size);
        }
        
        return newroot;
    }
    
    int largestBst(Node *root) {
        return solve(root).size;
    }
