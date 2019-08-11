#include <iostream>
#include<stdio.h>
#include<queue>
using namespace std;

struct bstnode{
bstnode * left;
bstnode * right;
int data;
};
bstnode* crt(int data){
bstnode* ns=new bstnode();
ns->data=data;
ns->left=NULL;
ns->right=NULL;
return ns;
}
bstnode* ins(bstnode *root,int data){
    if(root==NULL)
        {
        root=crt(data);

        }
    else if(data>root->data){
        root->right=ins(root->right,data);
    }
    else {
        root->left=ins(root->left,data);
    }
    return root;

}
bool srch(bstnode* root,int data){
if(root==NULL)
    return false;
if(root->data==data)
    return true;
else if(root->data>data)
    return srch(root->left,data);
else
    return srch(root->right,data);
}
int fmin(bstnode* root){
if (root->left==NULL)
return root->data;

return fmin(root->left);
}
int height(bstnode* root){
int lh,rh;
if (root==NULL)
    return -1;
lh=height(root->left);
rh=height(root->right);
if (lh>rh)
    return lh+1;
return rh+1;

}
void level_order(bstnode* root){
if (root==NULL)return;
queue<bstnode*> Q;
Q.push(root);
while(!Q.empty()){
    bstnode * temp=Q.front();
    cout<<(temp->data)<<"\n";
    if(temp->left!=NULL)
        Q.push(temp->left);
    if(temp->right!=NULL)
        Q.push(temp->right);
    Q.pop();

}}

int main()
{
bstnode * root;
root=NULL;
root=ins(root,10);
root=ins(root,9);
root=ins(root,15);
root=ins(root,13);
root=ins(root,20);
preorder(root);
return 0;
}
