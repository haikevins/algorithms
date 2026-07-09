#include <stdlib.h>

typedef struct 
{
    int value;
    int minValue;
} StackNode;

typedef struct 
{
    StackNode* data;
    int topIndex;
    int capacity;
} MinStack;


MinStack* minStackCreate() 
{
    MinStack* stack = (MinStack*)malloc(sizeof(MinStack));

    stack->capacity = 30000;
    stack->data = (StackNode*)malloc(stack->capacity * sizeof(StackNode));
    stack->topIndex = -1;

    return stack;
}

void minStackPush(MinStack* obj, int val) 
{
    obj->topIndex++;

    obj->data[obj->topIndex].value = val;

    if (obj->topIndex == 0) 
    {
        obj->data[obj->topIndex].minValue = val;
    } 
    else 
    {
        int previousMin = obj->data[obj->topIndex - 1].minValue;

        if (val < previousMin) 
        {
            obj->data[obj->topIndex].minValue = val;
        } 
        else 
        {
            obj->data[obj->topIndex].minValue = previousMin;
        }
    }
}

void minStackPop(MinStack* obj) 
{
    if (obj->topIndex >= 0) 
    {
        obj->topIndex--;
    }
}

int minStackTop(MinStack* obj) 
{
    return obj->data[obj->topIndex].value;
}

int minStackGetMin(MinStack* obj) 
{
    return obj->data[obj->topIndex].minValue;
}

void minStackFree(MinStack* obj) 
{
    free(obj->data);
    free(obj);
}