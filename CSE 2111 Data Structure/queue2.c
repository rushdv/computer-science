#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int num)
{
    if(rear == MAX-1){
        printf("\n Queue Overflow");
        return;
    }
    else if(front == -1 && rear == -1){
        front = rear = 0;
    }
    else{
        rear++;
    }
    queue[rear] = num;
}

int dequeue()
{
    int val;
    if(front == -1 || front > rear){
        printf("\n Queue is Empty");
        return -1;
    }
    else{
        val = queue[front];
        front++;
        if(front > rear){
            front = rear = -1;
        }
        return val;
    }
}

int peek()
{
    if(front == -1 || front > rear){
        printf("\n Queue is Empty");
        return -1;
    }
    else{
        return queue[front];
    }
}

void display()
{
    int i;
    printf("\n");
    if(front == -1 || front > rear){
        printf("\n Queue is Empty");
    }
    else{
        printf("\n Queue: ");
        for(i=front; i <= rear; i++){
            printf("%d ", queue[i]);
        }
    }
}

int main()
{
    display();
    enqueue(10);
    enqueue(10);
    enqueue(10);
    enqueue(10);

    display();
    dequeue();
    dequeue();

    enqueue(911);
    display();

    return 0;
}
