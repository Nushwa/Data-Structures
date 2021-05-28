#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
    int data;
    struct node *next;
};

struct node *head;
struct node *temp;

void deleteFirst()
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node) );

    if(head == NULL)
        printf("Can't delete");

    //temporary pointer
    temp = head;
    head = head-> next; //head is having 1st node memory so the address
                        //of next memory is stored in head
    printf("\nData deleted %d\n", temp-> data);
// link is destroyed now free memory
    free(temp);
    printf("\n SUCCESSFULLY DELETED");

}

void deleteMid()
{
    int  i=1, pos;
    struct node* node1;
    if(head == NULL)
        printf("Invalid");

    temp = head;
    printf("Enter position: ");
    scanf("%d", &pos);

    while (i<pos-1)

    {
        temp = temp-> next; //pointing to previous node we want to delete
        i++;
    }
    node1 = temp-> next; //next is pointing to the node we want to delete
    temp->next = node1->next;
    free(node1);
}

int deleteEnd()
{
    struct node *prevnode;
    temp = head;
    while(temp-> next != NULL) //traverse the linked list
    {
        prevnode = temp; //another pointer pointing to previous node
        temp = temp -> next; //point to last node and then stop
    }
    if(temp == head)
         head = 0; //if there is only 1 node
    else
        prevnode-> next = 0; //storing 0 to 2nd last node which is last

    free(temp);

}




int main()
{
    head = (struct node*)malloc(sizeof(struct node));
    struct node* head1 = (struct node*)malloc(sizeof(struct node));
    struct node* temp;

    printf("Enter the data: ");
    scanf("%d", &head -> data);
    head -> next = head1;

    head1 ->data = 3;
    head1 -> next = NULL;


        deleteFirst();

    deleteMid();
        temp = head;

    while(temp != NULL)
    {
        printf("%d " ,temp-> data);
        temp = temp->next;
    }

    return 0;
}
