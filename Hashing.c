#include "hash.h"

HashTable *create_table(int size)
{
    HashTable* temp=(HashTable*)malloc(sizeof(HashTable));
    temp->table=(int*)malloc(size*sizeof(int));

    temp->size=size;
    int i;
    for ( i=0;i<size;i++)
    temp->table[i]=-1;

    return temp;
}

void insert(HashTable *htable, int element)
{
int i,flag=0;
for(i=0;i<htable->size;i++)
    if(htable->table[i]==-1)flag=1;
if(flag==0)return ;
    int hashvalue=element%(htable->size);

    if(htable->table[hashvalue]==-1)
    {htable->table[hashvalue]=element;

    return;}

    else{
    for ( i=hashvalue;i<htable->size;i++)
        if(htable->table[i]==-1)
    {htable->table[i]=element;

    return;
    }
    for ( i=0;i<hashvalue;i++)
        if(htable->table[i]==-1)
    {htable->table[i]=element;

    return;
    }
    }
}

int search(HashTable *htable, int element)
{
    int hashvalue=element%(htable->size);
    if(htable->table[hashvalue]==element)return 1;
    for(int i=0;i<htable->size;i++)
        if(htable->table[i]==element)return 1;
    return 0;
}

void delete (HashTable *htable, int element)
{
    int hashvalue=element%(htable->size);
    if(htable->table[hashvalue]==element)htable->table[hashvalue]=-1;

}


void destroy_table(HashTable *htable)
{
    free(htable);

}
