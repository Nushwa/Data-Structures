#include<iostream>

using namespace std;

class node
{
public:
    int data;
    node *next;
    };
    node *newnode, *temp, *head;
class Stack{
public:
    int top;

    void push()
    {
        newnode = new node();
        cout << "Enter data: ";
        cin >> newnode->data;
        newnode->next = head;
        head = newnode;
        cout<< newnode->data << " Pushed into the stack" <<endl;
    }

    void pop()
    {
        if(head == NULL)
            cout << "The Stack is Empty" <<endl;
        temp = head;
        head = temp->next;
        cout << temp->data << " Popped" <<endl;
        free(temp);
    }

    void peek()
    {
        if(head == NULL)
            cout << "The Stack is Empty"<<endl;
        else
        {
            cout << "Top Element: " << head->data <<endl;
        }
    }

    void display()
    {
        temp = head;
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
    Stack st;
    st.push();
    st.push();
    st.push();
    st.display();
    st.pop();
    st.display();
    return 0;
}
