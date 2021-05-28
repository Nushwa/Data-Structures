#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct node{
    int data;
    struct node *next;
    }*head, *temp, *newnode, *tail;
int count;

int create()
{
    head = 0;
    newnode = (struct node*)malloc(sizeof(struct node) );
    printf("Enter the data: ");
    scanf("%d", &newnode->data);

    if(tail == NULL)
    {
        tail = newnode;
        tail->next = newnode;
    }
    else
    {
        newnode->next = tail->next; //tail->next is head
        tail->next = newnode; //last node is connected with first
        tail = newnode;
    }
}

int SecMaxNode()
{
    int first, sec;
    //first = sec = INT_MIN;
    //struct node *head;//*temp, *tail;
    first = head->data;

    if(head->next != tail->next)
    {
        sec = tail->next->next->data;
        temp = tail->next;

        while(temp->next != tail->next)
        {
            if(first < temp->data)
            {
                sec = first;
                first = temp->data;
            }
            else
                if(temp->data > sec && temp->data != first)
                sec = temp->data;

            temp = temp->next;
        }
         printf("The second largest val is: %d", sec);
    }
    else
        printf("The second largest val does not exist");
}

int main()
{
    int choice;
    do
    {
        printf("\n1-Create\n2-Insert At Beg\n3Insert At End\n4-Insert At Position");

        printf("\n5-Delete Beg\n6-Delete End\n7-Delete Middle\n8-Display \n");

        scanf("%d", &choice);
    if (choice == 1)
    create();
    else
        if(choice == 2)
        insertBeg();
    else
        if(choice == 3)
        insertAtEnd();
    else
        if(choice == 4)
            insertAtPos();
    else
        if(choice == 5)
            delBeg();
    else
        if(choice == 6)
            delEnd();
    else
        if(choice == 7)
           delMid();
    else
        if(choice == 8)
        display();
    else
        if(choice == 9)
        SecMaxNode();

    }while(choice != 0);

    return 0;
}

int insertBeg()
{
    newnode = (struct node*)malloc(sizeof(struct node) );
    printf("Enter the data: ");
    scanf("%d", &newnode->data);

    if(tail == NULL)
    {
        tail = newnode;
        head = newnode;
    }
    else
    {
        newnode->next = tail->next; //head
        tail->next = newnode;
    }


}
void display()
{
    temp = tail->next;

    if(tail == NULL)
    {
        printf("List is Empty");
    }
    else
    {
        temp = tail->next;
        while(temp->next != tail->next)
        {
            printf("%d ", temp->data);
            temp = temp->next;
            count++;
        }
        printf("%d ", temp->data); //to display the end
    }
}

int insertAtEnd()
{
     newnode = (struct node*)malloc(sizeof(struct node) );
    printf("Enter the data: ");
    scanf("%d", &newnode->data);

    if(tail == NULL)
    {
        tail = newnode;
        head = newnode;
    }
    else
    {
        newnode->next = tail->next;
        tail->next = newnode;
        tail = newnode;
    }
}

int insertAtPos()
{
    int pos, i;
    printf("Enter position: ");
    scanf("%d", &pos);

    if(pos > count)
        printf("Invalid Position");
    else
        if(pos == 1)
        insertBeg();
    else
    {
         newnode = (struct node*)malloc(sizeof(struct node) );
        printf("Enter the data: ");
        scanf("%d", &newnode->data);
        temp = tail->next;
        while(i < pos-1)
        {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;


    }
}


int delBeg()
{
    temp = tail->next;
    if(tail == 0)
        printf("The List is Empty");

    else
        if(temp->next == temp)
        {
            tail = NULL;
            free(temp);
        }
    else
    {
        tail->next = temp->next;
        free(temp);
    }
}

int delEnd()
{

}

int delMid()
{

}
