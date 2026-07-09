#include <stdbool.h>

typedef struct {
    char* data;
    int top;
    int capacity;
} Stack;

Stack* createStack(int capacity) 
{
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->data = (char*)malloc(capacity * sizeof(char));
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

void push(Stack* stack, char c) 
{
    if (stack->top < stack->capacity - 1) 
    {
        stack->top++;
        stack->data[stack->top] = c;
    }
}

char pop(Stack* stack) 
{
    if (stack->top >= 0) 
    {
        char c = stack->data[stack->top];
        stack->top--;
        return c;
    }
    return '\0';
}

bool isValid(char* s) 
{
    Stack* stack = createStack(10000);
    for (int i = 0; s[i] != '\0'; i++) 
    {
        char c = s[i];
        if (c == '(' || c == '[' || c == '{') 
        {
            push(stack, c);
        } 
        else 
        {
            if (stack->top == -1) 
            {
                return false;
            }
            char top = pop(stack);
            if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{')) 
            {
                return false;
            }
        }
    }
    return stack->top == -1;
}