#include "heap.h"
heap* heap_construct(int n){
    heap* tmp=(heap*)malloc(sizeof(heap)+n*sizeof(int));
    tmp->capacity=n;
    tmp->size=0;
    return(tmp);
}
void heap_destruct(heap* tmp){
    heap * temp=tmp;
    free(temp);
    tmp=NULL;
}
int heap_get_capacity(heap* tmp){
    return tmp->capacity;
}
int heap_get_size(heap* tmp){
    return tmp->size;
}

int heap_insert(heap* tmp,int data){
    if(tmp->capacity<=tmp->size)return 0;
    tmp->elements[tmp->size]=data;
    int element,child,parent;

    if(tmp->size!=0){
        for(int i=1;i<=tmp->size;i++){
            element=tmp->elements[i];
            child=i;
            parent=(child-1)/2;
            while(child>0&&tmp->elements[parent]>element){
                tmp->elements[child]=tmp->elements[parent];
                child=parent;
                parent=(child-1)/2;
            }
            tmp->elements[child]=element;
        }
    }
    tmp->size++;
    return 1;

}
int heap_get_min(heap* tmp){
    return tmp->elements[0];
}

void heap_remove(heap* tmp){
    int i=tmp->size-1,parent,child;
    int element=tmp->elements[i];
    tmp->elements[i]=tmp->elements[0];
    parent=0;
    if(i==1)child=-1;
    else child=1;
    if(i>2 && tmp->elements[2]<tmp->elements[1])
        child=2;
    while(child>=0 && tmp->elements[child]<element)
    {
        tmp->elements[parent]=tmp->elements[child];
        parent=child;
        child=2*parent+1;
        if(child+1<=i-1 && tmp->elements[child]<element)
        {
        child=child+1;
        }
        if(child>i-1)
            child=-1;
        }
        tmp->elements[parent]=element;
        tmp->size--;
}




