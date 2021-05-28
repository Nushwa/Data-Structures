#include<iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
} *temp, *front1,  *rear;

class Queue{
public:
    int Enqueue()
    {
        Node* newnode = new Node();
        front1 = 0;
        rear = 0;

        cout << "Enter data: ";
        cin >> newnode->data;
        newnode->next = 0;

        if(rear == NULL)
        {
            front1 = newnode;
            rear = newnode;
        }
        else
        {
            rear->next = newnode;
            rear = newnode;
        }

            //newnode->next = rear->next;

        cout << newnode->data << " Inserted" <<endl;
    }

    int Dequeue()
    {
        if(front1 == 0 )
            cout << "Empty" <<endl;
        else
        {
            temp = front1;
            cout << front1->data << " Deleted" <<  endl;
            front1 = front1->next;
            delete(temp);
        }
    }

    void display()
    {
        temp = front1;
        if(front1 == NULL && rear == NULL )
            cout << "Empty" <<endl;

            while(temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;

    }

};

int main()
{
    Queue q;

    int choice;
    do
    {

         cout << "1-Enqueue\n2-Dequeue\n3-Display" << endl;
        cin >> choice;

    if(choice == 1)
        q.Enqueue();
    else if(choice == 2)
        q.Dequeue();
    else if (choice == 3)
        q.display();

    } while(choice != 0);

}
