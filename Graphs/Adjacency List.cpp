#include<iostream>

using namespace std;

class Node
{
public:
    int data, weight;
    Node* next;
};

class list
{
public:
    Node* listptr;
};

class Graph
{
public:
    int visited[10];

    list *arr;
    int ver;

    Graph(int v)
    {
        ver = v;
        //list that will hold all the vertices
        arr = new list[ver];

        for( int i = 0; i < ver; i++ )
        {
            arr[i].listptr = NULL;
            //arr[i].temp = NULL;
            visited[i] = 0;
            //no node has been visited yet
        }
    }

    void create(int curr, int next, int weight)
    {
       /* int curr, next, weight;

        cout << "Start Node: ";
        cin >> curr;
        cout << "End Node: ";
        cin >> next;
        cout << "Enter weight: ";
        cin >> weight; */
Node* newNode = new Node;
        newNode->data = next;
        newNode->weight = weight;
        newNode->next = NULL;

        newNode->next = arr[curr].listptr;
        arr[curr].listptr = newNode;

        newNode = new Node;

        newNode->data = curr;
        newNode->next = NULL;

        newNode->next = arr[next].listptr;
        arr[next].listptr = newNode;
        cout << "Path created between " << curr << " and " << next << " with weight " << weight << endl;
    }


    void display(int src)
    {
        for (int i=0; i < ver ;i++)
            {
                Node *temp = arr[i].listptr;
                cout<<"\nList of vertex "<< i << ": ";
                while (temp)
                {
                    cout<<"  "<<temp->data << "(" << temp->weight << ")";
                    temp = temp->next;
                }
                cout<< endl;
            }
    }
};


int main()
{
    int choice;
    int c, s;
    Graph gr(4);
      gr.create(0,1, 4);
        gr.create(0, 2, 5);
        gr.create(0,4, 8);
        gr.create(1, 3, 2);
do
    {
    cout << "-------------------MENU------------------";
    cout << "\n1-Neighbour List of source vertex\n2-In Degree\n3-Out Degree\n4-Path Length of source and destination";
    cout << "\n5-Path Cost of source and destination\n6-DFS\n7-BFS\n8-shortest path search of all destination vertex\n9-Shortest path of source and destination vertex";
    cout << "\n0-Exit: ";
    cin >> choice;

        if(choice == 1)
        {
          gr.display();

        }


    }while (choice != 0);



    return 0;
}




