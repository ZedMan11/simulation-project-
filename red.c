#include <stdio.h>
#include<stdlib.h>
typedef struct 
{
int *arr;
int size;
int capacity;

    
}vector;

void init_vector(vector *v,int init_capacity)
{
   
v->arr=(int*)malloc(init_capacity*sizeof(int));
v->size=0;
v->capacity=init_capacity;
}
void push_back(vector *v ,int value)
{
    if(v->size>=v->capacity)
    {
    v->capacity *=2;
    v->arr=(int*)realloc(v->arr,v->capacity*sizeof(int));
    }
 v->arr[v->size++]=value;
}
void print(vector *v)
{
    for(int i=0;i<v->size;i++)
    printf("%d\n",v->arr[i]);
   
}
void pop_back(vector *v)
{
    if(v->size>0)v->size--;
}
void free_vector(vector *v) {
    free(v->arr);
    v->arr = NULL;
    v->size = 0;
    v->capacity = 0;
}


int main() {

vector f;
init_vector(&f,2);
push_back(&f,50);
push_back(&f,66);
push_back(&f,7);
print(&f);
puts("-----------------------------------------------------");
pop_back(&f);
print(&f);
free_vector(&f);
    return 0;
}
