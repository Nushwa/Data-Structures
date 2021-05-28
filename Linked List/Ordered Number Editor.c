#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
int data;
struct node *next;
}*head, *tail, *newnode, *temp;

int main()
{
    head = 0;
    tail = 0;
    int data, choice;
    do
    {
    printf("\n----MENU----\n1-Insert Number\n2-Find And Replace Number\n");
    printf("3-Replace All\n4-Delete One\n5-Delete All\n6-View Numbers\n7-Undelete\n");
    scanf("%d", &choice);
    if(choice == 1)
    {
        printf("Enter a Number: ");
        scanf("%d", &data);
        insertNum(data);
    }
    else
        if(choice == 2)
            SearchAndReplace();
    else
        if(choice == 3)
            ReplaceAll();
     else
        if(choice == 4)
            DeleteOne();
    else
        if(choice == 5)
            DeleteAll();
    else
        if(choice == 6)
            ViewNum();
    else
        if(choice == 7)
            Undelete();
        }
        while(choice != 0);

    return 0;
}

int insertNum(int data)
{
     newnode = (struct node*)malloc(sizeof(struct node));

     newnode->data = data;

        newnode->next = head;
        head = newnode;
        //tail = newnode;
        printf("%d Added\n", newnode->data);

}

int SearchAndReplace()
{
    int key, data;
    printf("Enter the number you want to Find: ");
    scanf("%d", &key);
    temp = head;
    while(temp != NULL)
    {
         if(temp->data == key)
         {
             printf("\nFound it\n");
             printf("Enter the data you want to replace it with: ");
             scanf("%d", &temp->data);

         }
         temp = temp->next;
    }
}

int ReplaceAll()
{
    temp = head;
    while(temp != NULL)
    {
        printf("Enter data: ");
        scanf("%d", &temp->data);
        temp = temp->next;
    }
}

int ViewNum()
{
    printf("Total Numbers are: ");
    temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp-> data);
        temp = temp->next;
    }
}

int DeleteOne()
{
    temp = head;
    head = head->next;
    temp->next = NULL;
    free(temp);

}

int DeleteAll()
{
    if(head == NULL)
    {
        printf("List is empty\n");
    }
    struct node* nextn;
    temp = head;
     while(temp != NULL)
     {
         nextn = temp->next;
         free(temp);
         temp = nextn;
     }

}

int Undelete()
{

}
