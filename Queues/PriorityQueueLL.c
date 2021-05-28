/*
Prepared By Nushwa Javed
Priority Queue using Linked List
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *prev, *next;
};

struct node *newnode, *head, *tail, *temp;

int create()
{
    newnode = (struct node*) malloc ( sizeof(struct node) );
    printf("Enter data > ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;
    newnode->prev = NULL;

    if(head == NULL)
    {
        head = newnode;
        tail = newnode;
    }
    else
    {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }

}

void display()
{
    temp = head;
    printf("\nQueue: ");
    while(temp != NULL)
    {
        printf("\nData: %d", temp->data);
        temp = temp->next;
    }
}

int enqueue()
{
    newnode = (struct node*) malloc ( sizeof(struct node) );

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;
    newnode->prev = NULL;

    if(head == NULL)
    {
        head = tail = newnode;
    }
    else
    {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;

    }
    printf("\n%d Enqueued\n", newnode->data);
}

int dequeue()
{

        temp = head;
    temp->next->prev = NULL;
    head = temp->next;
    printf("\n%d Dequeued\n", temp->data);
    free(temp);
}

int prdequeue()
{
    struct node *n1 = head;
        temp = head->next;


        while (temp->next != NULL)
        {
            if (n1->data > temp->data)
            {
                int ctemp = n1->data;
                n1->data = temp->data;
                temp->data = ctemp;
            }

            n1 = n1->next;

            temp = temp->next;
        }

        dequeue();
}

int prenqueue()
{

    enqueue();
     struct node *n1 = head;
        temp = head;
        while(temp->next != NULL)
        {
            if(n1->data > temp->data)
            {
                int ctemp = n1->data;
                n1->data = temp->data;
                temp->data = ctemp;

                n1 = n1->next;
            }
            temp = temp->next;
        }

}
int main()
{
    prenqueue();
     prenqueue();
      prenqueue();
      prenqueue();
      prenqueue();
    display();

    prdequeue();
    prdequeue();
        display();

        return 0;
}
