#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* next;
    node* prev;
}*temp, *head, *tail, *newnode;

class create{
public:
    void insertNode()
    {
        newnode = new node;

        cout << "Enter a data: ";
        cin >> newnode->data;

        newnode->next = 0;
        newnode->prev = 0;

        if(head == NULL)
        {
            head = tail = newnode;
        }
        else
        {
            tail -> next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
    }

    void display()
    {
        temp = head;
        while(temp != NULL)
        {
            cout << temp -> data << " ";
            temp = temp->next;
        }
    }

    void maxval()
    {

       temp = head;
       int maxx = temp->data;
       while(temp != NULL)
       {
           if(temp->data > maxx)
            maxx = temp->data;

           temp = temp->next;
       }
       cout << "The Maximum value: " << maxx<< endl;
    }
};


int main()
{
    create cn;
    cn.insertNode();
     cn.insertNode();
      cn.insertNode();
    cn.display();
    cout << endl;
    cn.maxval();
}
