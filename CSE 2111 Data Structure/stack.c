#include <stdio.h>
#define MAX 5

int myStack[MAX], top = -1;

void push(int myStack[], int val)
{
    if(top == MAX-1){
        printf("Stack Overflow");
    }
    else{
        top++;
        myStack[top] = val;
    }
}

int pop(int myStack[])
{
    int val;
    if(top == -1){
        printf("Stack is Empty");
        return -1;
    }
    else{
        
        val = myStack[top];
        top--;
        return val;
    }
}

void display(int myStack[])
{
    int i;
    if(top == -1){
        printf("Stack is Empty");
    }
    else{
        for(i=top; i>=0; i--){
            printf("\n %d", myStack[i]);
        }
        printf("\n");
    }
}

int peek(int myStack[])
{
    if(top == -1){
        printf("Stack is Empty");
        return -1;
    }
    else{
        return myStack[top];
    }
}

int main(){
    display(myStack);
    push(myStack, 10);
    push(myStack, 20);
    push(myStack, 30);
    push(myStack, 40);

    display(myStack);
    pop(myStack);

    display(myStack);
    push(myStack, 911);

    display(myStack);
    printf("\nCurrent top is: %d", peek(myStack));
}