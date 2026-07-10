#include <stdbool.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct
{
    int* queue;

    int front;
    int rear;

    int size;
} MyStack;


MyStack* myStackCreate() 
{
    MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
    obj->queue = (int*)malloc(MAX_SIZE * sizeof(int));

    obj->front = 0;
    obj->rear = 0;
    obj->size = 0;

    return obj;
}

void myStackPush(MyStack* obj, int x) 
{
    int oldSize = obj->size;

    // Push x to the back of the queue
    obj->queue[obj->rear] = x;
    obj->rear = (obj->rear + 1) % MAX_SIZE;
    obj->size++;

    /*
        Rotate the old elements to the back.
        After this, x will become the front element.
    */
    for (int i = 0; i < oldSize; i++) 
    {
        int temp = obj->queue[obj->front];
        obj->front = (obj->front + 1) % MAX_SIZE;

        obj->queue[obj->rear] = temp;
        obj->rear = (obj->rear + 1) % MAX_SIZE;
    }
}

int myStackPop(MyStack* obj) 
{
    int value = obj->queue[obj->front];

    obj->front = (obj->front + 1) % MAX_SIZE;
    obj->size--;

    return value;
}

int myStackTop(MyStack* obj) 
{
    return obj->queue[obj->front];
}

bool myStackEmpty(MyStack* obj) 
{
    return (obj->size == 0);
}

void myStackFree(MyStack* obj) 
{
    free(obj->queue);
    free(obj);
}