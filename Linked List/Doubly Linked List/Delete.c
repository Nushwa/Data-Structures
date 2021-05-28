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
        printf("\nMenu\n1-Create\n2Delete From Beginning\n3Delete From the End\n4-Delete From Position\n");
        printf("5-Display\n0 to end\n");
        scanf("%d", &choice);

        if(choice == 1)
            create();
        else
            if(choice == 2)
                DeleteBeg();
         else
            if(choice == 3)
                DeleteEnd();
        else
            if(choice == 4)
                DeletePos();
        else
            if(choice == 5)
                display();
    }
    while(choice != 0);



    return 0;
}

int create()
{
    newnode = (struct node*) malloc (sizeof(struct node));
    printf("Enter the data: ");
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
        newnode -> prev = tail;
        tail->next = newnode;
        tail = newnode;

    }
}

int DeleteBeg()
{
    if(head == NULL)
    {
        printf("Cannot be Deleted.");
    }
    else
    {
        temp = head;

        head = head->next;
        head->prev = NULL;

        free(temp);
    }
}

int DeletePos()
{
    int pos,i=1;
    printf("Enter the position: ");
    scanf("%d", &pos);

    if(pos > count)
        printf("Invalid Position. ");
    else
    {
        temp = head;
        while(i < pos)
        {
            temp = temp->next;
            i++;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        temp->next=NULL;
        temp->prev=NULL;
        free(temp);

    }
}
int DeleteEnd()
{
    temp = tail;
    tail = tail->prev;
    temp->prev = NULL;
    tail->next = NULL;

    free(temp);

}

void display()
{
    printf("\nThe List is: ");
    temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
        count++;
    }
}
