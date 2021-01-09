#include "6b.h"
stack* stack_initialize(int size)
{
stack * st=(stack*)malloc(sizeof(stack));
st->arr=(int*)malloc(size*sizeof(int));
st->top=-1;
}

void stack_push(stack *ptr_stack, int key)
{
ptr_stack->top++;
ptr_stack->arr[ptr_stack->top]=key;
}

void stack_pop(stack *ptr_stack)
{ if(ptr_stack->top!=-1)
    ptr_stack->top--;
}

int stack_is_empty(stack *ptr_stack)
{
if(ptr_stack->top==-1)return 1;
return 0;
}

int stack_peek(stack *ptr_stack)
{
if(ptr_stack==NULL)return -1;
return ptr_stack->arr[ptr_stack->top];
}

void stack_destroy(stack *ptr_stack)
{
stack * temp=ptr_stack;
free(temp);
ptr_stack=NULL;
}

void convert_infix_to_postfix(const char *source_infix,char *target_postfix)
{

    stack *st=stack_initialize(strlen(source_infix));
    int pr1,pr2,temp;
    int index=0,res=0;
    while(source_infix[index]!='\0')
    {
        if(isalnum(source_infix[index]))
        {
            target_postfix[res++]=source_infix[index];
        }
        else if(source_infix[index]=='('||source_infix[index]=='['||source_infix[index]=='{')
        {
                stack_push(st,source_infix[index]);
        }
        else if(source_infix[index]==')'||source_infix[index]==']'||source_infix[index]=='}')
        {
            switch(source_infix[index]){
            case ')':temp='(';
            break;
            case '}':temp='{';
            break;
            case ']':temp='[';
            break;
            }
            while((stack_peek(st)!=temp)&&(st->top!=-1))
            {
                target_postfix[res++]=(char)stack_peek(st);
                stack_pop(st);
            }
            stack_pop(st);
            target_postfix[res]='\0';

        }
        else
        {
            if(source_infix[index]=='*'||source_infix[index]=='/')
                pr1=1;
            else
                pr1=0;
            if(stack_peek(st)==(int)'*'||stack_peek(st)==(int)'/')
                pr2=1;
            else
                pr2=0;
            while(pr2>pr1&&st->top!=-1){

                target_postfix[res++]=(char)stack_peek(st);
                stack_pop(st);
                if(stack_peek(st)==(int)'*'||stack_peek(st)==(int)'/')
                pr2=1;
                else
                pr2=0;
            }

            stack_push(st,source_infix[index]);
        }
       index++;
    }

    while(st->top!=-1)
    {
        target_postfix[res++]=stack_peek(st);
        stack_pop(st);
    }
stack_destroy(st);
}