#include<iostream>

using namespace std;

class node{
public:
    int data;
    node *next;
};
node *head, *temp, *newnode, *tail;
int count;

class Insertion{
public:

    void create()
    {
        newnode = new node;
        cout<< "Enter data: " <<endl;
        cin >> newnode->data;
        head = newnode;

        newnode->next = temp;
        temp = newnode;
    }


    int insertAtBeg()
    {
        newnode = new node;
        cout << "Enter data to insert at end: " <<endl;
        cin >> newnode->data;

        newnode->next = head;
        head = newnode;

        cout << newnode->data << " Added." <<endl;
    }

    int insertAtEnd()
    {
        newnode = new node;
        cout << "Enter data to insert at end: " <<endl;
        cin >> newnode->data;

        newnode->next = NULL;

        if(head == NULL)
            head = newnode;
        else
        {
            temp = head;
            while(temp-> next != NULL)
                temp = temp->next;

            temp->next = newnode;
        }
    }
};

class displayList
{
public:
    void display()
    {
        temp = head;
        while(temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
            count++;
        }
        cout << endl;
    }
};


class Deletion{
public:
    int Deletebeg()
    {
        temp = head;
        head = head->next;
        cout << temp->data << " Deleted." <<endl;
        delete temp;
    }

    int DeleteEnd()
    {
        node* prevnode = new node;
        temp = head;
        while(temp->next != NULL)
        {
            prevnode = temp;
            temp = temp->next;
        }

        prevnode->next = NULL;
        cout << temp->data << " Deleted." <<endl;
        delete temp;
    }

    int DeletePos()
    {
        node* next = new node;
        int pos, i = 1;
        cout << "Enter Position to delete: ";
        cin >> pos;

        temp = head;
        if(head == 0)
            printf("The List is Empty");

            while(i < pos-1)
            {
                temp = temp->next;
                i++;
            }
            next = temp -> next;
            temp->next = next->next;
            delete next;
    }

};

int main()
{
    Insertion ins;
    displayList dis;
    Deletion del;

    ins.create();
    ins.create();
    ins.create();
    dis.display();

    ins.insertAtBeg();
    ins.insertAtEnd();

    dis.display();

    del.Deletebeg();
    del.DeletePos();
    dis.display();



    return 0;
}
