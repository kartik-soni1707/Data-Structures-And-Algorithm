#include "et.h"

void push(Node *stc[],int *top,Node * temp){
++(*top);
stc[(*top)]=temp;

}
Node * pop(Node * stc[],int *top){
Node *temp=stc[(*top)];
(*top)--;
return temp;
}
int isOper(char c){

if(c=='+'||c=='-'||c=='*'||c=='/')return 1;
else return 0;
}
Node * createNode(char data){

    Node * temp=(Node*)malloc(sizeof(Node));
    temp->data=data;
    temp->left=temp->right=temp->prev=NULL;
    return temp;
}

Node * createExpressionTree(char* a,int len)
{
    int top=-1;
    Node *stack[100];
Node * temp,*a1,*b1;
    for (int i=0;i<len;i++){
        if(isOper(a[i])==1)
        {
            a1=pop(stack,&top);
            b1=pop(stack,&top);
            temp=createNode(a[i]);

            temp->right=a1;
            temp->left=b1;
            push(stack,&top,temp);
        }
        else{
             temp=createNode(a[i]);
            push(stack,&top,temp);
        }
        }

temp=pop(stack,&top);

return temp;
}
void inorder(Node *root)
{

 if(root==NULL)return;
 inorder(root->left);
  printf("%c",root->data);
  inorder(root->right);
}

void preorder(Node *root)
{
 if(root==NULL)return;
  printf("%c",root->data);
  preorder(root->left);
  preorder(root->right);
}

void postorder(Node *root)
{

if(root==NULL)return;
    postorder(root->left);
  postorder(root->right);
  printf("%c",root->data);


}

void freeTree(Node *root)
{
if(root==NULL)return ;
else {
if(root->left!=NULL)freeTree(root->left);
else if(root->right!=NULL)freeTree(root->right);
free(root);
}
}

