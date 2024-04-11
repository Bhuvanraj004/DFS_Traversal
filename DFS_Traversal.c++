#include <iostream>
#include <list> 
#include <memory>

class Graph
{
private:
int _V;
bool _directed;
std::unique_ptr< std::list<int> > adj; void DFSUtil(int v, bool visited[]);

public:
Graph(int V, bool directed); void AddEdge(int v, int w); void DepthFirstSearch(int s);
};

Graph::Graph(int V, bool directed) : adj(new std::list<int>[V])
{
_V = V;
_directed = directed;
}

void Graph::AddEdge(int v, int w)
{
std::list<int>* adjacency = adj.get(); adjacency[v].push_back(w);

if (!_directed)
{
adjacency[w].push_back(v);
}
}

void Graph::DFSUtil(int v, bool visited[])
{

visited[v] = true; std::cout << v << " "; std::list<int>::iterator i;
 
for (i = (adj.get())[v].begin(); i != (adj.get())[v].end(); ++i) if (!visited[*i])
DFSUtil(*i, visited);
}

void Graph::DepthFirstSearch(int v)
{
std::unique_ptr<bool[]> visited(new bool[_V]); for (int i = 0; i < _V; i++)
visited[i] = false;

DFSUtil(v, visited.get());
}

int main()
{
Graph g(7, true); g.AddEdge(0, 1);
g.AddEdge(0, 2);
g.AddEdge(0, 3);
g.AddEdge(1, 0);
g.AddEdge(1, 5);
g.AddEdge(2, 5);
g.AddEdge(3, 0);
g.AddEdge(3, 4);
g.AddEdge(4, 6);
g.AddEdge(5, 1);
g.AddEdge(6, 5);

std::cout << "Depth First Traversal starting from vertex 2:\n"; g.DepthFirstSearch(2);

return 0;
}
