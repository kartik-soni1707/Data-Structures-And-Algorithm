#include<stdio.h>
#include<stdlib.h>

typedef struct dll{
int data;
struct dll  *next,*prev;
}Node;

Node * create(int data){
Node * temp=(Node*)malloc(sizeof(Node));
temp->data=data;
temp->next=NULL;
temp->prev=NULL;
return temp;
}
void insf(Node ** head,int value){
Node * T=create(value);
T->next=(*head);
if((*head)!=NULL)
        (*head)->prev=T;
(*head)=T;
}
void disp(Node ** head){
Node * ptr=*head;
while(ptr!=NULL){
    printf("%d->",ptr->data);
    ptr=ptr->next;
}
}
int main() {
Node *head=NULL;
insf(&head,1);
disp(&head);
insf(&head,2);
disp(&head);

return 0;
}
