#include <stdio.h>
#define MAX 5

int mystack[MAX], top = -1;

void push(int mystack[], int val)
{
    if (top == MAX-1){
        printf("\n Stack Overflow");
    }
    else{
        top++;
        mystack[top] = val;
    }
}

int pop(int mystack[])
{
    int val;
    if(top == -1){
        printf("\n Stack is Empty");
        return -1;
    }
    else{
        val = mystack[top];
        top--;
        return val;
    }
}

void display(int mystack[])
{
    int i;
    if(top == -1){
        printf("\n Stack is Empty");
    }
    else{
        for(i=top ; i>=0; i--){
            printf("\n %d", mystack[i]);
        }
        printf("\n");
    }
}

int peek(int mystack[])
{
    if(top== -1){
        printf("\n Stack is Empty");
        return -1;
    }
    else{
        return mystack[top];
    }
}

int main()
{
    display(mystack);
    push(mystack, 11);
    push(mystack, 13);
    push(mystack, 14);
    push(mystack, 15);

    display(mystack);
    pop(mystack);

    display(mystack);
    push(mystack, 4564);

    display(mystack);
    printf("\n Current stack top is : %d", peek(mystack));
}
