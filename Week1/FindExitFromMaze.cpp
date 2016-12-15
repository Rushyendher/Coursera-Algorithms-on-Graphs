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
    void DFSUlit(int u,bool visited[],vector<int> &vec);
public:
    Graph(int v);
    void addEdgeFrom(int src,int dest);
    void DFS(int u,int v);
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

void Graph::DFS(int u,int v)
{
    bool *visited = new bool[vertices];
    for(int i = 0;i<vertices;i++)
        visited[i] = false;
    
    vector<int> vec;
    DFSUlit(u,visited,vec);
    
    auto found = find(vec.begin(),vec.end(),v);
    
    if(found != vec.end())
        cout << "1" << endl;
    else
        cout << "0" << endl;
}

void Graph::DFSUlit(int u,bool visited[],vector<int> &vec)
{
    visited[u] = true;
    vec.push_back(u);
    
    list<int>::iterator it;
    
    for(it = array[u].begin();it != array[u].end();it++)
    {
        if(!visited[*it])
            DFSUlit(*it,visited,vec);
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
    
    int u,v;
    cin >> u >> v;
    graph->DFS(u,v);
    
    return 0;
}