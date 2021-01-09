#include "queue.h"
static node *create_node(int id, int time, node *link)
{
node* temp=(node*)malloc(sizeof(node));
temp->id=id;
temp->link=link;
temp->time=time;
return temp;
}
void list_initialize(List *ptr_list)
{
ptr_list->head=ptr_list->tail=NULL;
ptr_list->number_of_nodes=0;
}
const int node_get_id(node *node_ptr)
{
if(node_ptr!=NULL)return node_ptr->id;
}

const int node_get_time(node *node_ptr)
{
if(node_ptr!=NULL)return node_ptr->time;
}

void list_insert_rear(List *ptr_list, int id, int time)
{
node * tmp=create_node(id,time,NULL);
if(ptr_list->number_of_nodes==0) ptr_list->head=ptr_list->tail = tmp;
else
    {ptr_list->tail->link=tmp;
    ptr_list->tail=tmp;
    }
ptr_list->number_of_nodes++;
}

void list_delete_front(List *ptr_list)
{
node* temp;
if(ptr_list->head==NULL)return;
temp=ptr_list->head;
ptr_list->head=temp->link;
if(temp->link==NULL)ptr_list->tail=NULL;
free(temp);
ptr_list->number_of_nodes--;
}

void list_destroy(List *ptr_list)
{
List * temp=ptr_list;
ptr_list=NULL;
free(temp);
}

void queue_initialize(Queue *queue_list)
{
queue_list->ptr_list=(List*)malloc(sizeof(List));
list_initialize(queue_list->ptr_list);
	}

void queue_enqueue(Queue *ptr, int id, int time)
{
list_insert_rear(ptr->ptr_list,id,time);
	}

void queue_dequeue(Queue *ptr)
{
list_delete_front(ptr->ptr_list);
}

int queue_is_empty(Queue *ptr)
{
if(ptr->ptr_list->number_of_nodes==0)return 1;
return 0;
}

void queue_peek(Queue *ptr)
{
if(ptr->ptr_list->number_of_nodes!=0)
printf("%d %d\n",node_get_id(ptr->ptr_list->head),node_get_time(ptr->ptr_list->head));
else
    printf("Empty Queue\n");
}

void queue_destroy(Queue *ptr)
{
Queue * temp;
temp=ptr;
free(temp);
ptr=NULL;
}

const int queue_find_person(Queue *ptr_queue, int t)
{
node * ptr=ptr_queue->ptr_list->head;
int time=t;
if(ptr!=NULL)
{
    while(ptr!=NULL){
        time-=ptr->time;
        if(time<=0)break;
        ptr=ptr->link;
        queue_dequeue(ptr_queue);
    }

}
if(time<=0)
printf("%d",node_get_id(ptr));
else
printf("Empty Queue");
printf("\n");
}
