#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

class Graph
{
private:
    int vertices;
    vector< list<int> > array;
    void DFSUlit(int u,bool visited[]);
public:
    Graph(int v);
    void addEdgeFrom(int src,int dest);
    void printGraph();
    void DFS();
};

Graph::Graph(int v)
{
    vertices = v;
    array.resize(v);
}

void Graph::addEdgeFrom(int src,int dest)
{
    array[src].push_back(dest);
    array[dest].push_back(src);
}

void Graph::printGraph()
{
    list<int>::iterator it;
    
    for(int i = 1;i<vertices;i++)
    {
        for(it = array[i].begin();it != array[i].end();it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
}

void Graph::DFS()
{
    bool *visited = new bool[vertices];
    for(int i = 0;i<vertices;i++)
        visited[i] = false;
    
    int connectedComponents = 0;
    
    for(int i = 1;i<vertices;i++)
    {
        if(!visited[i])
        {
            DFSUlit(i,visited);
            connectedComponents++;
        }
    }   
    cout << connectedComponents << endl;
}

void Graph::DFSUlit(int u,bool visited[])
{
    visited[u] = true;
    
    list<int>::iterator it;
    
    for(it = array[u].begin();it != array[u].end();it++)
    {
        if(!visited[*it])
            DFSUlit(*it,visited);
    }
}

int main()
{
    int vertices,edges;
    
    cin >> vertices >> edges;
    
    Graph *graph = new Graph(vertices+1);
    
    int src,dest;
    
    for(int i = 0;i<edges;i++)
    {
        cin >> src >> dest;
        graph->addEdgeFrom(src,dest);
    }

    graph->DFS();
    
    return 0;
}