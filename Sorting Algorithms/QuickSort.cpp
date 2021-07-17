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
class QuickSortAlgo{
public:
    Node* Tail(Node* temp)
    {
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        return temp;
    }

    Node *middle(Node *head, Node *end, Node *stList, Node* enList)
    {
        Node *pivot = end;
        Node *prev = NULL;
        Node *cur = head;
        Node *tail = pivot;

        while (cur != pivot)
        {
            if(cur-> data < pivot->data)
            {
                if(stList == NULL)
                    stList = cur;

                prev = cur;
                cur = cur->next;
            }
            else
            {
                if(prev)
                    prev->next = cur->next;

                Node *temp = cur->next;
                cur->next = NULL;
                tail->next = cur;
                tail = cur;
                cur = temp;
            }
        }
        if(stList == NULL)
            stList = pivot;

        enList = tail;
        return pivot;
    }

    Node *QuickSort(Node *head, Node *end)
    {
        if(!head || head == end)
            return head;
        Node *nHead = NULL;
        Node *nEnd = NULL;
        Node *pivot = middle(head, end, nHead, nEnd);

        if(nHead != pivot)
        {
            Node *temp = nHead;

            while (temp->next != pivot)
                temp = temp->next;

            temp->next = NULL;
            nHead = QuickSort(nHead, temp);
            temp = Tail(nHead);
            temp->next = pivot;
        }

        pivot->next = QuickSort(pivot->next, nEnd);

        return nHead;

    }

    void quickSortal(Node *node)
    {
        node = QuickSort(node, Tail(node));
        return;
    }
};
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    QuickSortAlgo qs;
    int size;
    cout << "Enter the size of list: ";
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        generateList();

    }
    cout << "Before Sorting: ";
    printList();

    qs.quickSortal(head);

    cout << "\nAfter Sorting: ";
    printList();

    return 0;
}
