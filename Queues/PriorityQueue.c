#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define SIZE 10

int front=-1, rear=-1;
int prq[SIZE];

int isEmpty();
int isFull();
int getMin();
int enqu();
int dequ();
int display();


int main()
{
    int choice;
    do
    {
        printf("\nMenu\n1-Enqueue\n2-Dequeue\n0 to End\n");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            enqu();
            break;
        case 2:
            dequ();
            break;
        default:
            printf("Invalid");
            break;
        }
    }
    while(choice != 0);

    return 0;
}

int isEmpty()
{
    return(rear == -1 && front == -1);
}

int isFull()
{
    return(rear + 1 == SIZE);
}

int enqu()
{
    int n;
    if(isFull() )
        printf("The Queue is Full\n");
    else
    {
        printf("Enter data: ");
        scanf("%d", &n);
        rear = rear + 1;
        prq[rear] = n;
        printf("Enqueued %d\n", prq[rear] );
    }
}

int getMin()
{
    int m=0,i;
    for(i = 1; i< rear; i++)
    {
        if(prq[i] < prq[m])
            m=i;
    }
    return m;
}

int dequ()
{
    int num = 0, i;
    int index = 0;
    if(isEmpty() )
        printf("Queue is Empty\n");
    else
    {
        index = getMin();
        num = prq[index];
        for(i = index; i < rear; i++)
            prq[i] = prq[i+1];

        rear--;
    }
    printf("Dequeued %d\n", num);
}
