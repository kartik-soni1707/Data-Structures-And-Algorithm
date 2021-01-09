#include<stdio.h>
#include "bst.h"
void tree_initialize(Tree *tree)
{
    tree->root=NULL;
}
Node * create(int data){
Node* temp=(Node*)malloc(sizeof(Node));
temp->data=data;
temp->left=temp->right=NULL;
return temp;
}
Node * insert(Node *root,int data){
if(root==NULL)return create(data);
if(root->data>data)
root->left=insert(root->left,data);
else
root->right=insert(root->right,data);
return root;
}
void tree_insert(Tree *tree, int data)
{
tree->root=insert(tree->root,data);
}
Node * findMin(Node * node){
while(node && node->left!=NULL)
    node=node->left;
return node;
}
Node* dlt(Node * node,int key){
if(node==NULL)return ;
if(node->data>key)node->left=dlt(node->left,key);
else if(node->data<key)node->right=dlt(node->right,key);
else{
    if(node->left==NULL){
        Node * tmp=node->right;
        destroy(node);
        return tmp;
    }
    else if(node->right==NULL){
        Node * tmp=node->left;
        destroy(node);
        return tmp;
    }
    Node * temp=findMin(node->right);
    node->data=temp->data;
    node->right=dlt(node->right,temp->data);
}

return node;
}
void tree_delete(Tree *tree, int element)
{
   tree->root=dlt(tree->root,element);

}

void tree_inorder(Node *r)
{
 	if(r==NULL)return;
 	tree_inorder(r->left);
 	printf("%d",r->data);
 	tree_inorder(r->right);
}

void tree_preorder(Node *r)
{
    if(r==NULL)return;
 	printf("%d",r->data);
 	tree_inorder(r->left);
    tree_inorder(r->right);
}

void tree_postorder(Node *r)
{
    if(r==NULL)return;
 	tree_inorder(r->left);
    tree_inorder(r->right);
    printf("%d",r->data);
}

void postorder(Tree *t)
{
  tree_postorder(t->root);
  printf("\n");
}

void preorder(Tree *t)
{
  tree_preorder(t->root);
  printf("\n");
}

void inorder(Tree *t)
{
  tree_inorder(t->root);
  printf("\n");
}

void destroy(Node *r)
{
Node* temp=r;
  r=NULL;
  free(temp);
}

void tree_destroy(Tree *t)
{
destroy(t->root);
free(t);
}
