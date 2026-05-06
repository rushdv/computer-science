#include <stdio.h>
#define MAX 5

int mystack[MAX], top = -1;

void push(int mystack[], int val)
{
    if (top == MAX - 1)
    {
        printf("\n Stack Overflow");
    }
    else
    {
        top++;
        mystack[top] = val;
    }
}

int pop(int mystack[])
{
    int val;
    if (top == -1)
    {
        printf("\n Stack is empty");
        return -1;
    }
    else
    {
        val = mystack[top];
        top--;
        return val;
    }
}

void display(int mystack[])
{
    int i;
    if (top == -1)
    {
        printf("\n Stack is Empty");
        
    }
    else
    { 
        for (i = top; i >= 0; i--)
        {
            printf("\n %d", mystack[i]);
        }
        printf("\n");
    }
}

int peek(int mystack[])
{
    if(top == -1){
        printf("Stack is empty");
        return -1;
    }
    else{
        return mystack[top];
    }
}

int main(){
    display(mystack);
    push(mystack, 12);
    push(mystack, 22);
    push(mystack, 32);

    display(mystack);
    pop(mystack);

    display(mystack);
    push(mystack,43534);

    display(mystack);
    printf("\n Current top is: %d", peek(mystack));
}