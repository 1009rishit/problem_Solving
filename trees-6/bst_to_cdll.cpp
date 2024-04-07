#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
 Node *prev=NULL;
    Node *head=NULL;
    void inorder(Node *root)
    {
        if(root==NULL) return;
        inorder(root->left);
        if(head==NULL) head=prev=root;
        else {
            prev->right=root;
            root->left=prev;
        }
        prev=root;
        inorder(root->right);
    }
    Node *bTreeToCList(Node *root)
    {
      inorder(root);
      head->left=prev;
      prev->right=head;
      return head;
    }
}