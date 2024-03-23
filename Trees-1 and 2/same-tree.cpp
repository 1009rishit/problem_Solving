 #include<bits/stdc++.h>
 using namespace std;
 struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL) return true;
        if(p==NULL && q!=NULL) return false;
        if(p!=NULL && q==NULL) return false;
        bool left=isSameTree(p->left,q->left);
        bool right=isSameTree(p->right,q->right);
        int val1=p->val,val2=q->val;
        bool a;
        if( val1==val2) a=true;
        else a=false;
         if(left&& right&& a){
             return true;
         }
         else return false;
            }