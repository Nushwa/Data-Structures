#include<iostream>

using namespace std;
struct Node
{
    int data;
    Node* next;
};
Node* temp, *head;

Node* generateList()
{
    Node* newNode = new Node();
    cout << "Enter Data: ";
    cin >> newNode->data;

    temp = head;

    if(head == NULL)
        head = newNode;
    else
    {
        while(temp->next != NULL) //traverse the list
        {
            temp = temp->next;
        }
        newNode->next = temp->next; //last node
        temp->next = newNode;
    }
    cout << newNode->data << " Inserted." << endl;
}

void printList()
{
    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

class MergeSortAlgo
{
public:
    Node* MiddleElement(Node* head)
    {
        if(head == NULL)
            return head;

        Node *sl, *fa; //slow -> 1 increment, fast -> 2 increment
        sl = head;
        fa = head;
        while(fa->next != NULL && fa->next->next != NULL)
        {
            sl = sl->next;
            fa = fa->next->next;  //fast will move 2 steps forward
        }
        return sl;
    }

    Node* Merge(Node *le, Node* ri)
    {
        Node* sortList = new Node;  //to store sorted list
        Node* curr; //for traversal
        curr = sortList;

        while( le != NULL && ri != NULL) //traverse and find the smallest item
        {
            if(le->data > ri->data) //1st list next item > 2nd
            {
                curr->next = ri; //2nd to the sorted list
                ri = ri->next;
            }
            else
            {
                curr->next = le;
                le = le->next;
            }
            curr = curr->next;
        }
        if(le == NULL) //if list finishes then take all the nodes and put it at the end
        {
         for(Node* temp = ri; temp!= NULL; temp = temp->next)
            {
                curr->next = temp;
                curr = curr->next;
            }
        }
        else
        {
            for(Node* temp = le; temp!= NULL; temp = temp->next)
            {
                curr->next = temp;
                curr = curr->next;
            }
        }
        return sortList->next;
    }

    Node* Sort(Node* head)
    {
        if(head == NULL || head->next == NULL)
            return head;

        Node* mid, *half;
        mid = MiddleElement(head); //find the middle of list

        half = mid->next;  //breaking the link to 2 parts
        mid->next = NULL;
        return Merge( Sort(head), Sort(half) ); //recursively call the function and keep breaking it until 1
    }
};

int main()
{
    int size;
    MergeSortAlgo ms;
    cout << "Enter the size of the list: ";
    cin >> size;

    for(int i = 0; i <s size; i++)
        generateList();

    cout << "\nSorted List is: ";
    head = ms.Sort(head);

    printList();


}
