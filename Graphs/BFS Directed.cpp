#include<iostream>
#include<queue>
#include<stack>
#define INFINITY -1

using namespace std;

enum Color {
    UNDISCOVERED,
    DISCOVERED,
    PROCESSED
};

class Graph {
private:
      int **adjMatrix;
      int vertexCount;
	  // below attributes are for BFS
	  int *state;
	  int *parent;
	  int *level;
public:
    Graph(int vertexCount);
    ~Graph();
	int getVertexCount();
    void addEdgeUndirected(int i, int j);
	void addEdgeDirected(int i, int j);

    void removeEdgeDirected(int i, int j);
	void removeEdgeUndirected(int i, int j);
    int isEdge(int i, int j);
    void display();
	void initializeState();
	void showLevelInfo();
	void showParentInfo();
	void showStateInfo();

	void printPath(int source, int destination);
    void BFS(int startNode);
	//-------------------------------------------
};
Graph::Graph(int vertexCount) {
    this->vertexCount = vertexCount;

	this->state = new int[vertexCount];
	this->parent = new int[vertexCount];
	this->level = new int[vertexCount];

    adjMatrix = new int*[vertexCount];
    for (int i = 0; i < vertexCount; i++) {
        adjMatrix[i] = new int[vertexCount];
           for (int j = 0; j < vertexCount; j++)
              adjMatrix[i][j] = false;
    }
}
Graph::~Graph() {
    for (int i = 0; i < vertexCount; i++){
         delete[] adjMatrix[i];
    }
            delete[] adjMatrix;

}
void Graph::initializeState(){
	for(int i=0; i<this->vertexCount; i++){
		this->state[i] = 0; // 0=undiscovered, 1=discovered, 2=processed
		this->parent[i]= -1; //-1=no parent, else parent
		this->level[i] = -1;  // -1=no level info
	}
}
void Graph::showLevelInfo(){
	cout<<"Graph Level Info...\n";
	for(int i=0; i<this->vertexCount; i++){
		cout<<"Node "<<i<<"\tNode Level: "<<this->level[i]<<"\n";
	}
}
void Graph::showParentInfo(){
	cout<<"Graph Parent Info...\n";
	for(int i=0; i<this->vertexCount; i++){
		cout<<"Node "<<i<<"\tNode Parent: "<<this->parent[i]<<"\n";
	}
}
void Graph::showStateInfo(){
	cout<<"Graph State Info...\n";
	for(int i=0; i<this->vertexCount; i++){
		cout<<"Node "<<i<<"\tNode State: "<<this->state[i]<<"\n";
	}
}
int Graph::getVertexCount(){
	return this->vertexCount;
}
void Graph::addEdgeUndirected(int i, int j) {
    if (i >= 0 && i < vertexCount && j >= 0 && j < vertexCount) {
		adjMatrix[i][j] = true;
		adjMatrix[j][i] = true;
    }
}
void Graph::addEdgeDirected(int i, int j) {
    if (i >= 0 && i < vertexCount && j >= 0 && j < vertexCount) {
		adjMatrix[i][j] = true;
    }
}
void Graph::removeEdgeUndirected(int i, int j) {
    if (i >= 0 && i < vertexCount && j >= 0 && j < vertexCount) {
		adjMatrix[i][j] = false;
		adjMatrix[j][i] = false;
    }
}
void Graph::removeEdgeDirected(int i, int j) {
    if (i >= 0 && i < vertexCount && j >= 0 && j < vertexCount) {
		adjMatrix[i][j] = false;
    }
}
int Graph::isEdge(int i, int j) {
    if (i >= 0 && i < vertexCount && j >= 0 && j < vertexCount)
        return adjMatrix[i][j];
    else{
		cout<<"Invalid vertex number.\n";
		return false;
	}
}
void Graph::display(){
    int  u,v; //vertex
	cout<<"\t   ";
	for(u=0; u<vertexCount; u++){
		cout<<u<<" ";
	}
    for(u=0; u<vertexCount; u++) {
        // cout << "\nadj[" << (char) (u+48) << "] -> ";
        cout << "\nAdj[" << u << "] -> ";
        for(v=0; v<vertexCount; ++v) {
            cout << " " << adjMatrix[u][v];
        }
    }
    cout << "\n\n";
}

void Graph::BFS(int s)
{
    cout << "Breadth First Search" << endl;

    state = new int[this->vertexCount];
    level = new int[this->vertexCount];
    parent = new int[this->vertexCount];

    for (int i = 0; i < 4; i++)
    {
        state[i] = UNDISCOVERED;
        level[i] = INFINITY;
        parent[i] = 0;
    }
    state[s] = DISCOVERED;

    queue<int> Q;
    Q.push(s);

    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        cout << u << " ,";


        for (int col = 0; col < this->vertexCount; col++){
            if (isEdge(u, col) && state[col] == UNDISCOVERED)

                {
                    state[col] = DISCOVERED;
                    level[col] = level[col] + 1;

                    parent[col] = u;


                    Q.push(col);
                }

            //cout << level[col] << " ";
            //cout << parent[col] << " ";

            state[u] = PROCESSED;
        }
        }

}


int main(){
	Graph g(5);
	g.initializeState();
	g.addEdgeDirected(0, 1);
    g.addEdgeDirected(0, 3);
    g.addEdgeDirected(0, 4);
    g.addEdgeDirected(1, 2);
    g.addEdgeDirected(1, 3);
    g.addEdgeDirected(3, 0);
    g.addEdgeDirected(3, 2);
    g.addEdgeDirected(3, 4);
	g.display();
	// this is the graph that is in your lecture slide

	int startNode=0;
	g.BFS(startNode);
	//g.showLevelInfo();
	//g.showParentInfo();
	//int destination = 7;
//	g.printPath(startNode, destination);
	//cout<<"\n";
}
