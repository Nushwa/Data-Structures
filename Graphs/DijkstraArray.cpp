#include <iostream>
#define SIZE 20
#define INF 1000000000; //infinity

using namespace std;

int adjMatrix[SIZE][SIZE], size;

class DijkstraAlgo
{
public:
    int dist[SIZE];
    bool visited1[SIZE];

    DijkstraAlgo(int s)
    {
        size = s;
    }

    int dijstra(int start, int target) //from start to target
    {
        int i, j;
        visited1[start] = true; //the starting point will be visited

        for (i = 0; i <= size; ++i)
        {
            visited1[i] = false;                //initialize every point with 0
            dist[i] = adjMatrix[start][i]; //Initializing distance
        }

        for (i = 0; i < size; ++i)
        {
            int min = INF; // calculation for every point

            int pos;

            //loop through all vertices
            for (j = 0; j <= size; ++j)
            {
                //for 2nd time
                //Record the minimum point
                if (!visited1[j] && min > dist[j])
                {
                    pos = j;
                    min = dist[j];
                }
            }

            //put the vertix to visited
            visited1[pos] = true; //visited

            //update the distance
            for (j = 0; j <= size; ++j)
            {
                if (!visited1[j] && (dist[j] > (dist[pos] + adjMatrix[pos][j])))
                {//update the shortest path
                    dist[j] = dist[pos] + adjMatrix[pos][j];
                }
            }
        }

        return dist[target];
    }

};

int main()
{
    int ans;
    int temp = INF;
    DijkstraAlgo di(4);

     //every point -> infinity
     for (int i = 0; i <= size; ++i)
    {
        for (int j = 0; j <= size; ++j)
        {
            adjMatrix[i][j] = INF;
        }
    }

    //Graph vertices with weights
    int no, e1, e2, w;
    cout << "Enter no of vertex: ";
    cin >> no;

    for(int i = 0; i < size; i++)
    {
        cout << "Enter edge: ";
    cin >> e1 >> e2;
    cout << "Enter weight: ";
    cin >> w;

    adjMatrix[e1][e2] = w;
    }


    /*adjMatrix[0][1] = 4;
    adjMatrix[0][7] = 8;
    adjMatrix[1][7] = 11;
    adjMatrix[1][2] = 8;
    adjMatrix[7][8] = 7;
    adjMatrix[7][6] = 1;
    adjMatrix[6][8] = 6;
    adjMatrix[6][5] = 2;
    adjMatrix[8][2] = 2;
    adjMatrix[2][5] = 4;
    adjMatrix[2][3] = 7;
    adjMatrix[3][5] = 14;
    adjMatrix[3][4] = 9;
    adjMatrix[5][4] = 10;*/

      //initializing the adjacent matrix
    for (int i = 0; i <= size; ++i)
    {
        for (int j = 0; i <= size; i++)
        {
            if (adjMatrix[i][j] == temp)
                adjMatrix[i][j] = adjMatrix[j][i];
        }
    }

    int c1,c2;

    cout << "Enter source and destination for shortest path: ";
    cin >> c1 >> c2;
    cout << "Vertex \t\t Distance from Source\n" ;

    int i = 3;
        ans = di.dijstra(0, 3);
       cout << i << "\t\t" << ans << endl;


    return 0;
}
