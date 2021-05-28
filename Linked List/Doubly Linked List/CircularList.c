#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
    struct node* prev;
};
struct node *head, *newnode, *temp, *tail;
int count;

int main()
{
    int choice;
    do
    {
    printf("\n1-Create\t2-Display\n3-Insert Beg\n4-Insert End\n5-Delete Beg\n6-Delete End\n");

    scanf("%d",&choice);

    if(choice == 1)
        Create();
    else
        if(choice == 2)
            display();

    else
        if(choice == 3)
            insertAtBeg();
     else
        if(choice == 4)
            insertEnd();

    else
        if(choice == 5)
            delBeg();

    else
        if(choice == 6)
            delEnd();

    }while(choice != 0);

    return 0;
}

void Create()
{
    newnode = (struct node*)malloc(sizeof(struct node) );
    printf("Enter data: ");
    scanf("%d", &newnode->data); //accessing the data of a node

    if(head == NULL)
    {
        head = newnode;
        tail = newnode;
    }
    else
    {
        tail->next = newnode;
        newnode->prev = tail;
        newnode->next = head;
        head->prev = newnode;
        tail=newnode;

    }
}

void display()
{
    temp = head;
    while(temp-> next != head)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d ", temp->data);
}

int insertAtBeg()
{
    newnode = (struct node*)malloc(sizeof(struct node) );
    printf("Enter data: ");
    scanf("%d", &newnode->data);

     if(head == NULL)
    {
        head = newnode;
        newnode->next = head;
        newnode->prev = tail;
    }
    else
    {
        newnode->next = head;
        head->prev = newnode;
        newnode->prev = tail;
        tail->next = newnode;
        head = newnode;
    }
}

int insertEnd()
{
     newnode = (struct node*)malloc(sizeof(struct node) );
    printf("Enter data: ");
    scanf("%d", &newnode->data);

     if(head == NULL)
    {
        head = newnode;
        newnode->next = head;
        newnode->prev = tail;
    }
    else
    {
        newnode->prev = tail;
        tail->next = newnode;
        newnode->next = head;
        head->prev = newnode;
        tail = newnode;
    }
}


int delBeg()
{
    temp = head;
    if(head == NULL)
        printf("The List is Empty");
    else if(head->next == head)
    {
        head = tail = NULL;
        free(temp);
    }
    else
    {
        head = head->next;
        head->prev = tail;
        tail->next = head;
        free(temp);
    }
}

int delEnd()
{
    temp = tail;
    if(head == NULL)
        printf("The List is Empty");
    else if(head->next == head)
    {
        head = tail = NULL;
        free(temp);
    }
    else
    {
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
        free(temp);
    }

}
