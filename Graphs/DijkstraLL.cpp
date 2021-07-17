//Dijkstra using Linked List for Directed Directed Graph

#include<iostream>
#include<limits>
#define SIZE 20

using namespace std;

class Node
{
public:
    int data;
    int weight;
    Node *next;

    Node(int da, int w)
    {
        data = da;
        weight = w;
        next = NULL;
    }

};

class Graph
{
public:
    bool directed;
    Node *edges[SIZE];

    Graph(bool d)
    {
        directed = d;
        for(int i = 0; i < SIZE; i++)
        {
            edges[i] = NULL;
        }
    }

    Graph()
    {

    }

    void InsertEdge(int x1, int x2, int weight, bool directed)
    {
        if(x1 < SIZE && x2 < SIZE )
        {
            Node *NewEdge = new Node(x2, weight);
            NewEdge->next = edges[x1];
            edges[x1] = NewEdge;
            if(!directed)
                InsertEdge(x2, x1, weight, true);
        }
    }

    void printGraph()
    {
        for(int ver = 0; ver < SIZE; ver++)
        {
            if(edges[ver] != NULL)
            {
                cout << "Vertex " << ver << " has neighbors: " << endl;
                Node *curr = edges[ver];

                while(curr != NULL)
                {
                    cout << curr->data << " ";
                    curr = curr->next;

                }
                cout << endl;
            }
        }
    }


};

//initializing the
    void initialize(bool visit[], int dis[], int par[])
    {
        for(int i = 0; i < SIZE; i++)
        {
            visit[i] = false;
            dis[i] = numeric_limits<int>::max();  //maximum finite value
            par[i] = -1;
        }
    }

void DijkstraAl(Graph *g, int par[], int dist[], int st)
{
    bool visited[SIZE];
    Node* curr;
    int verCurrent, neighbour, weight, Min_dist;
    //Graph *gr = new Graph();

    initialize(visited, dist, par);

    dist[st] = 0;
    verCurrent = st;

    while(visited[verCurrent] == false)
    {
        visited[verCurrent] = true;
        curr = g->edges[verCurrent];

        while(curr != NULL)
        {
            neighbour = curr->data;
            weight = curr->weight;

            if( (dist[verCurrent] + weight) < dist[neighbour] )
            {
                dist[neighbour] = dist[verCurrent] + weight;
                par[neighbour] = verCurrent;
            }
            curr = curr->next;
        }

        //set next vertex to vertex with smallest distance
        Min_dist = numeric_limits<int>::max();
        for(int i = 0; i < SIZE; i++)
        {
            if(!visited[i] && (dist[i] < Min_dist) )
            {
                verCurrent = i;
                Min_dist = dist[i];
            }
        }

    }
}

void display(int ve, int par[])
{
    if(ve < ( SIZE && par[ve] != -1) )
    {
        cout << par[ve] << " ";
        display(par[ve], par);
    }
}

void displayDist(int st, int di[])
{
    for(int i = 0; i < SIZE; i++)
    {
        if(di[i] != numeric_limits<int>::max())
        {
            cout << "Shortest distance from " << st << " to " << i << " is " << di[i] << endl;
        }
    }
}

int main()
{

    Graph *gr = new Graph(false);

    int parent[SIZE];
    int dist[SIZE];
    int start = 0;


    gr->InsertEdge(0, 1, 9, false);
    gr->InsertEdge(0, 3, 3, false);
    gr->InsertEdge(1, 3, 2, false);
    gr->InsertEdge(1, 2, 11, false);



    cout << "Printing Graph" << endl;
    gr->printGraph();

    DijkstraAl(gr, parent, dist, start);
    cout << "Printing Shortest Distance: " << endl;
    //for(int i =0; i < 4; i++)
    //{
        display(1, parent);
        displayDist(start, dist);
    //}

    delete gr;


    return 0;
}
