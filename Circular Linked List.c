#include "cll.h"
void position_insert(List* cll, int data, int pos)
{
if(pos<0 || pos>cll->length+1)return;
Node *temp=create_node(data);
if(cll->length==0)
{
temp->next=temp;
cll->head=temp;
}else{
if(pos==0)
{   temp->next=cll->head;
    cll->tail->next=temp;
    cll->head=temp;}
else{
pos--;
Node *ptr=cll->head;
for(;ptr!=cll->tail;ptr=ptr->next,pos--)
if(pos==0)break;
temp->next=ptr->next;
ptr->next=temp;
}
if(temp->next==cll->head)cll->tail=temp;

}
cll->length++;
}
void position_delete(List* cll, int pos)
{
    if(pos<0 || pos>cll->length+1||cll->head==NULL)return;

    if(cll->length==1)
    {
        Node * tmp=cll->head;
        cll->head=cll->tail=NULL;
        cll->length--;
        free(tmp);
        return;
    }


    Node *ptr=cll->head;
    Node * prev;
    for(;ptr!=cll->tail;ptr=ptr->next,pos--)
    {
        if(pos==0)break;
        prev=ptr;
    }
    if(ptr==cll->head)
    {
        cll->head=cll->head->next;
        cll->tail->next=cll->head;

    }
    else if(ptr==cll->tail)
    {
        cll->tail=prev;
        prev->next=cll->head;

    }
    else{
        prev->next=ptr->next;

    }

    free(ptr);
    cll->length--;
}

int josephus(List* cll, int k)
{
     Node *curr = cll->head;
     Node *prev = cll->head;
    while (cll->length!=1)
    {
        int c=0;
        while (c != k+1)
        {
            prev = curr;
            curr = curr->next;
            c++;
        }
        prev->next = curr->next;
        free(curr);
        cll->length--;
        curr = prev->next;
    }

cll->head=cll->tail=curr;
return curr->data;
}
