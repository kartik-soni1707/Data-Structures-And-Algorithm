#include "6a.h"

static Node* create_Node(int data, Node* link) {
	Node* temp =  (Node*)malloc(sizeof(Node));
	temp -> data = data;
	temp -> link = link;
	return temp;
}

void List_initialize(List* ptr_List)
{
//TODO
ptr_List=(List*)malloc(sizeof(List));
ptr_List->head=NULL;
ptr_List->number_of_Nodes=0;
}

void List_insert_front(List* ptr_List, int data)
{
Node * new_node=NULL;
new_node=create_Node(data,ptr_List->head);
ptr_List->head=new_node;
}

const int Node_get_data(Node *Node_ptr)
{
if(Node_ptr!=NULL)return Node_ptr->data;
}

void List_delete_front(List* ptr_List)
{
Node *temp=ptr_List->head;
if(temp==NULL)return;
ptr_List->head=ptr_List->head->link;
free(temp);
}

void List_destroy(List* ptr_List)
{
List * temp=ptr_List;
ptr_List=NULL;
free(temp);
}


void stack_initialize(Stack *ptr_stack)
{
ptr_stack->ptr_List=(List*)malloc(sizeof(List));
List_initialize(ptr_stack->ptr_List);
}

void stack_push(Stack *ptr_stack, int key)
{
List_insert_front(ptr_stack->ptr_List,key);
ptr_stack->ptr_List->number_of_Nodes++;
}

void stack_pop(Stack *ptr_stack)
{
List_delete_front(ptr_stack->ptr_List);
ptr_stack->ptr_List->number_of_Nodes--;
}

int stack_is_empty(Stack *ptr_stack)
{
if(ptr_stack->ptr_List->number_of_Nodes==0)return 1;
return 0;
}

const int stack_peek(Stack *ptr_stack)
{
if(ptr_stack->ptr_List->head!=NULL)return Node_get_data(ptr_stack->ptr_List->head);
}

void stack_destroy(Stack *ptr_stack)
{
List_destroy(ptr_stack->ptr_List);
Stack *temp =ptr_stack;
ptr_stack=NULL;
free(temp);
}

int postfix_eval(const char* expression)
{
 Stack st;
 stack_initialize(&st);
 int index=0,x,y;
 while(expression[index]!='\0'){
    if(isdigit(expression[index])){
    stack_push(&st,expression[index]-'0');
    }
    else{
    x=stack_peek(&st);
    stack_pop(&st);
    y=stack_peek(&st);
    stack_pop(&st);

    switch(expression[index]){
    case '+':stack_push(&st,x+y);
    break;
    case '-':stack_push(&st,y-x);
    break;
    case '*':stack_push(&st,x*y);
    break;
    case '/':stack_push(&st,y/x);
    break;
    }
 }
 index++;
 }
int z=stack_peek(&st);
stack_pop(&st);
stack_destroy(&st);
return z;
}
