#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
int data;
struct node *next;
};

struct node *newnode, *temp, *head;
int count = 0;

int insertBeg()
{
    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter the data to insert in beginning: ");
    scanf("%d", &newnode->data);
    newnode ->next = head;
    head = newnode;


    printf("\nNode is\nData: %d\nAddress: %d\n", *newnode, newnode);
}


int insertEnd()
{
    newnode = (struct node*)malloc(sizeof(struct node));
    struct node* last = head;

    printf("\nEnter the data you want to insert at end: ");
    scanf("%d", &newnode -> data);

    newnode -> next = NULL;
    if(head == NULL)
        head = newnode;

    while( last->next != NULL )
    last = last->next;

    last->next = newnode;

    printf("\nNode is\nData: %d\nAddress: %d\n", *newnode, newnode);


}

void display()
{
    temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp-> data);
        temp = temp->next;
        count++;
    }
}

int insertMid()
{
    int pos, i=1;
    newnode = (struct node*) malloc(sizeof(struct node) );
    printf("Enter the position you want to insert: ");
    scanf("%d", &pos);

    if(pos > count )
        printf("Invalid position.");
    else
    {
        temp = head;
        //traverse
        while(i < pos)
        {
            temp = temp-> next;
            i++;
        }
        printf("Enter data you want to insert: ");
        scanf("%d", &newnode->data);
        newnode->next = temp->next;
        temp->next = newnode;

        printf("\nNode is\nData: %d\nAddress: %d\n", *newnode, newnode);
    }
}

int main()
{
    head = NULL;
    struct node* head1 = (struct node*) malloc(sizeof(struct node) );
    struct node* head2 = (struct node*) malloc(sizeof(struct node) );

    head1->data = 4;
    head1->next = head2;


    head2 -> data= 8;
    head2 -> next = NULL;


    if(head == NULL)
        head = head1;


    printf("\nInserting at Beginning\n");
    insertBeg();
    display();
    printf("\nInserting at the End\n");
    insertEnd();

    printf("\nInserting at n Position\n");
    insertMid();
    printf("\nThe List is: ");
    display();


    return 0;
}
