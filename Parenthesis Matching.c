#include "5a.h"

static Node* create_Node(int data, Node* link)
 {

// TODO - create and allocate dynamic space
Node * temp=(Node*)malloc(sizeof(Node));
temp->data=data;
temp->link=link;

return temp;
}


void list_initialize(List* ptr_list)
{
//TODO - initialize structure members to default values
ptr_list->head=NULL;
ptr_list->number_of_Nodes=0;
}


void list_insert_front(List* ptr_list, int data)
{
//TODO - perform linked list implementation of push operation.
Node * new_node=NULL;
new_node=create_Node(data,ptr_list->head);
ptr_list->head=new_node;
}


const int Node_get_data(Node *Node_ptr)
{
//TODO - return the top most element
if(Node_ptr!=NULL)return Node_ptr->data;
}


void list_delete_front(List* ptr_list)
{
//TODO - perform linked list implementation of pop operation.
Node *temp=ptr_list->head;
if(temp!=NULL)
    ptr_list->head=ptr_list->head->link;
free(temp);

}


void list_destroy(List* ptr_list)
{
//TODO - free the allocated space
List * temp=ptr_list;
ptr_list=NULL;
free(temp);
}

void Stack_initialize(Stack *ptr_Stack)
{
//TODO - get the memory allocation for stack, and intern call list initialize
ptr_Stack->ptr_list=(List*)malloc(sizeof(List));
list_initialize(ptr_Stack->ptr_list);
}

void Stack_push(Stack *ptr_Stack, int key)
{
//TODO	 - call the function list_insert_front
list_insert_front(ptr_Stack->ptr_list,key);
ptr_Stack->ptr_list->number_of_Nodes++;
}

void Stack_pop(Stack *ptr_Stack)
{

//TODO- call the function list_delete_front
list_delete_front(ptr_Stack->ptr_list);
ptr_Stack->ptr_list->number_of_Nodes--;
}

int Stack_is_empty(Stack *ptr_Stack)
{
//TODO	- return 0 if stack is not empty
if(ptr_Stack->ptr_list->number_of_Nodes==0)return 1;
return 0;
}

const int Stack_peek(Stack *ptr_Stack)
{

//TODO	- return the top most element of the stack
if(ptr_Stack->ptr_list->head!=NULL)return ptr_Stack->ptr_list->head->data;
}

void Stack_destroy(Stack *ptr_Stack)
 {
//TODO	- deallocate
Stack *temp =ptr_Stack;
ptr_Stack=NULL;
free(temp);
}

int match_parenthesis(const char* string)
{
//TODO - implement the code to match paranthesis in a string which is passed as a parameter.
Stack stc;

Stack_initialize(&stc);
int index=0;

while(string[index]!='\0'){

switch(string[index]){
case'(':
case'{':
case'[':Stack_push(&stc,(int)string[index]);
break;

case')':
        if(!Stack_is_empty(&stc)){
        if(Stack_peek(&stc)==(int)('('))
            {
            Stack_pop(&stc);
            break;}
        else return 0;
        }
        else return 0;
        break;
case'}':if(!Stack_is_empty(&stc)){
        if(Stack_peek(&stc)==(int)'{')
            {
            Stack_pop(&stc);
            break;}
        else return 0;
        }
        else return 0;
        break;
case']':if(!Stack_is_empty(&stc)){
        if(Stack_peek(&stc)==(int)'[')
            {
            Stack_pop(&stc);
            break;}
        else return 0;
        }
        else return 0;
        break;
        }
        index++;
}
if(Stack_is_empty(&stc))return 1;
return 0;

}
