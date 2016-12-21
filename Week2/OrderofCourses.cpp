#include <iostream>
#include <vector>
#include <iterator>
#include <list>
#include <stack>

using namespace std;

class Graph
{
private:
    int vertices;
    vector <list<int> > array;
    void topologicalSortUtil(int node,bool *visited,stack<int> &s);

public:
    Graph(int v);
    void addEdgeFrom(int src,int dest);
    void printGraph();
    void topologicalSort();
};

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

Graph::Graph(int v)
{
    vertices = v;
    array.resize(v);
}

void Graph::addEdgeFrom(int src,int dest)
{
    array[src].push_back(dest);
}


void Graph::topologicalSortUtil(int node,bool *visited,stack<int> &s)
{
    visited[node] = true;
    list<int>::iterator it;

    for(it = array[node].begin();it != array[node].end();it++)
    {
        if(!visited[*it])
            topologicalSortUtil(*it,visited,s);
    }

    s.push(node);
}

void Graph::topologicalSort()
{
    bool *visited = new bool[vertices];
    for(int i = 1;i<vertices;i++)
        visited[i] = false;
    stack<int> s;

    for(int i = 1;i<vertices;i++)
    {
        if(!visited[i])
            topologicalSortUtil(i,visited,s);
    }

    while(!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}

int main()
{
    int v,e;
    cin >> v >> e;
    
    Graph *graph = new Graph(v+1);
    
    int src,dest;
    while(e--)
    {
        cin >> src >> dest;
        graph->addEdgeFrom(src,dest);
    }    
    //graph->printGraph();
    
    graph->topologicalSort();

    return 0;
}