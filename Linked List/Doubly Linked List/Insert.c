#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node *head, *newnode, *temp, *tail;
int count;

int create();
int insertAtBeg();
int insertAtEnd();
int insertAtPos();
void display();
int search();


int main()
{
    int choice;
    do
    {
        printf("\nMENUU\n1-Enter Data\n2-Insert At Beg\n3-Insert At End\n4-Insert at Position\n5-Display\n");
    printf("6-Search\n");
    printf("0 to end\n");
    scanf("%d", &choice);
    if(choice == 1)
    {
        create();
    }
    else
        if(choice == 2)
            insertAtBeg();

    else
        if(choice == 3)
             insertAtEnd();

    else
        if(choice == 4)
        insertAtPos();

    else
        if(choice == 5)
        display();
     else
        if(choice == 6)
            search();
    }
    while(choice != 0);

    return 0;
}

int create()
{
    newnode = (struct Node*)malloc(sizeof(struct Node) );
    printf("Enter data: ");
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

int insertAtBeg()
{
    newnode = (struct Node*)malloc(sizeof(struct Node) );

    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    newnode ->prev = NULL;

    if(head == NULL)
    {
        head = newnode;
        tail = newnode;
    }
    else
    {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;

    }
}

int insertAtEnd()
{
    newnode = (struct Node*)malloc(sizeof(struct Node) );

    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    newnode ->prev = NULL;

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


int insertAtPos()
{
    int pos, i=0;
    newnode = (struct Node*)malloc(sizeof(struct Node) );
    printf("Enter the position: ");
    scanf("%d", &pos);


    if(pos < count)
        printf("Invalid Position");
    else if(pos == 1)
        insertAtBeg();
    else
    {
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        newnode ->prev = NULL;

        temp =head;
        //traverse the list
        while(i < pos-1)
        {
            temp = temp->next;
            i++;
        }

        newnode->prev = temp;
        newnode->next = temp -> next;
        temp->next = newnode;

        newnode->next->prev = newnode;
    }
}

int InsertBeforeCurrent()
{
    struct Node *temp, *newNode, *current;
    temp = current->prev;

    temp->next = newNode;
    newNode->prev = temp;

    current->prev = newNode;
    newNode->next = current;

}

int search()
{
    int key, flag = 0;
    printf("Enter the data you want to search: ");
    scanf("%d", &key);
   temp = head;
   while(temp != NULL)
   {
       if(temp->data == key)
        printf("Found it\nData: %d\nAddress: %d", temp->data, &temp);


       temp = temp->next;
   }

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
