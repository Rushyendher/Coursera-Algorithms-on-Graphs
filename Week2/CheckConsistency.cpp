#include <iostream>
#include <vector>
#include <iterator>
#include <list>

using namespace std;

class Graph
{
private:
    int vertices;
    vector <list<int> > array;
    bool isCyclicUtil(int node,bool *visited,bool *visitedStack);
public:
    Graph(int v);
    void addEdgeFrom(int src,int dest);
    bool isCyclic();
    void printGraph();
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

bool Graph::isCyclicUtil(int node,bool *visited,bool *visitedStack)
{
    visited[node] = true;
    visitedStack[node] = true;

    list<int>::iterator it;
    for(it = array[node].begin();it != array[node].end();it++)
    {
        if(!visited[*it] && isCyclicUtil(*it,visited,visitedStack))
            return true;
        else if(visitedStack[*it])
            return true;
    }
    visitedStack[node] = false;
    return false;
}

bool Graph::isCyclic()
{
    bool *visited = new bool[vertices];
    bool *visitedStack = new bool[vertices];
    for(int i = 1;i<vertices;i++)
    {
        visited[i] = false;
        visitedStack[i] = false;
    }
    
    /*

    int totalCycles = 0;

    for(int i = 1;i<vertices;i++)
    {
        if(!visited[i])
        {
            if(isCyclicUtil(i,visited,visitedStack)) 
                totalCycles++;
        }
    }

    */

    for(int i = 1;i<vertices;i++)
    {
        if(!visited[i])
        {
            if(isCyclicUtil(i,visited,visitedStack)) 
                return true;
        }
    }
    return false;
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
    
    if(graph->isCyclic())
        cout << "1" << endl;
    else
        cout << "0" << endl;
    
    return 0;
}