#include<stdio.h>
#include<stdlib.h>
#include "sll.h"

void insert_at_end(List *list, int data) {
	
	Node * head;
	Node *  temp=(Node*)malloc(sizeof(Node));
	temp->data=data;
	temp->link=NULL;
	if(list->head==NULL)
    {
       list->head=temp;
    }
    else{
        head=list->head;
        while(head->link!=NULL)head=head->link;
        head->link=temp;
    }
    list->number_of_nodes++;
}

void list_delete_front(List* list) {
	if(list->head==NULL)return;
	Node * temp;
	temp=list->head;
	list->head=list->head->link;
	free(temp);
	list->number_of_nodes--;
}

void list_insert_at (List *list, int data, int position)
{
	Node *  temp=(Node*)malloc(sizeof(Node));
	temp->data=data;
	temp->link=NULL;
    Node * pointer=list->head;
	if(list->head==NULL){
        list->head=temp;
	}

    else if(position==0){
        temp->link=list->head;
        list->head=temp;

    }
    else{
        if(position>list->number_of_nodes)return;
        while(position-1>0){pointer=pointer->link;position--;}
        temp->link=pointer->link;
        pointer->link=temp;
    }
    list->number_of_nodes++;
	}

void list_reverse(List* list)
{
 	Node * current,*previous,*next;
 	previous=NULL;
 	next=NULL;
 	current=list->head;
 	while(current!=NULL){
        next=current->link;
        current->link=previous;
        previous=current;
        current=next;
 	}
 	list->head=previous;
}


