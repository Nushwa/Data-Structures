#include<iostream>
#define SIZE 10
using namespace std;

class Graph{
public:

    int graph[SIZE][SIZE];
    int verNo;
    int weight;

    Graph()
    {
        this->verNo = 0;
        //Initializing the 2-D array to 0
        for(int i = 0; i < SIZE; i++)
        {
            for(int j = 0; j < SIZE; j++)
                graph[i][j] = 0;
        }
    }

        void create()
        {
            cout << "Creating" << endl;
            char ch;
            //do
            {
                int n1, n2;
                int m1,m2;
                cout << "Enter 1st vertex: ";
                cin >> n1;
                m1 = n1;
                n1--;
                cout << "Enter 2nd vertex: ";
                cin >> n2;
                m2 = n2;
                n2--;
                cout << "Enter Weight: ";
                    cin >> weight;

                if(n1 > SIZE || n2 > SIZE)
                {
                    cout << "Array is Full." << endl;
                    return;
                }

                if(graph[n1][n2] == 0)
                {
                    //directed graph
                    graph[n1][n2] = weight;
                    cout << "Edge created between " << n1 << " and " << n2 << endl;

                }
                else if(graph[n1][n2] == weight || graph[n2][n1] == weight)
                    cout << "\nEdge already exists" << endl;
            }
        }


    void display()
    {
        cout << "Printing Graph" << endl;
        for (int i = 0; i < SIZE; i++)
			{
				cout << i;
				for (int j = 0; j < SIZE; j++)
				{
					cout << "\t"<< graph[i][j];
				}
				cout << "\n";
			}
    }
};
int main()
{
    Graph gr;
    int x;
    do
    {
        cout << "\nDIRECTED WEIGHTED ADJACENCY GRAPH\n";
        cout << "\n1-Create\n2-Display\n3-Exit\n";
        cin >> x;

        switch(x)
        {
        case 1:
            gr.create();
        break;
        case 2:
            gr.display();
        break;


        }
    }
    while (x != 3);

    return 0;
}
