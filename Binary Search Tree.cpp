#include <iostream>
#include<stdio.h>
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
int main()
{
bstnode * root;
root=NULL;
root=ins(root,10);
root=ins(root,15);
root=ins(root,20);
root=ins(root,25);
int x;
cin>>x;
if (srch(root,x)==1)
    cout<<"True";
return 0;
}
