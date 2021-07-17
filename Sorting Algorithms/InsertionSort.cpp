#include <iostream>

using namespace std;
struct Node
{
    int data;
    Node *next;
};
Node *head, *temp;
class InsertionSortAlgo
{
public:
    InsertionSortAlgo()
    {
        head = NULL;
    }
    Node* create()
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
    void InsertionSort()
    {
        Node* temp = head, *sortl;
        int store;
        while (temp != NULL)
        {
            for (sortl = temp->next; sortl; sortl = sortl->next)
            {
                if(temp->data > sortl->data)
                {
                    store = temp->data;
                    temp->data = sortl->data;
                    sortl->data = store;
                }
            }
            temp = temp->next;
        }
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
};
int main()
{
	InsertionSortAlgo is;
	int size, i;
	cout << "Enter the size of the list: ";
	cin >> size;

	for(i = 0; i < size; i++)
    {
        is.create();
    }
	is.InsertionSort();
	is.printList();
    return 0;
}
