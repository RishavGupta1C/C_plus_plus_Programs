// An Iterative C++ program to do DFS traversal from a given source vertex. DFS(int s) traverses vertexes
// reachable from s.
#include<bits/stdc++.h>

using namespace std;

// This class represents a directed graph using adjacency
// list representation
class Graph
{
	int V; // No. of vertexes
	list<int> *adj; // adjacency lists
public:
	Graph(int V); // Constructor
	void addEdge(int v, int w); // to add an edge to graph
	void DFS(int s); // prints all vertexes in DFS manner from a given source s
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s list.
}

// prints all not yet visited vertexes reachable from s
void Graph::DFS(int s)
{
	// Initially mark all vertexes as not visited
	vector<bool> visited(V, false);

	// Create a stack for DFS
	stack<int> stack;

	// Push the current source node.
	stack.push(s);

	while (!stack.empty())
	{
		// Pop a vertex from stack and print it
		int s = stack.top();
		stack.pop();

		// Stack may contain same vertex twice. So
		// we need to print the popped item only
		// if it is not visited.
		if (!visited[s])
		{
			cout << s << " ";
			visited[s] = true;
		}

		// Get all adjacent vertexes of the popped vertex s
		// If a adjacent has not been visited, then push it to the stack.
		for (auto i = adj[s].begin(); i != adj[s].end(); ++i)
			if (!visited[*i])
				stack.push(*i);
	}
}

// Driver program to test methods of graph class
int main()
{
	Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 5);

    cout<<"Following the DFS (starting from vertex 0) \n";
    g.DFS(0);

	return 0;
}


/*
// Recursive C++ program to print DFS traversal from a given vertex in a  given graph
#include <bits/stdc++.h>

using namespace std;

// Graph class represents a directed graph using adjacency list representation
class Graph {
public:
    map<int, bool> visited;
    map<int, list<int> > adj;

    // function to add an edge to graph
    void addEdge(int v, int w);

    // DFS traversal of the vertexes reachable from v
    void DFS(int v);
};

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

void Graph::DFS(int v)
{
    // Mark the current node as visited and print it
    visited[v] = true;
    cout << v << " ";

    // Recur for all the vertexes adjacent to this vertex
    list<int>::iterator itr;

    for (itr = adj[v].begin(); itr != adj[v].end(); ++itr)
        if (!visited[*itr])
            DFS(*itr);
};

int main()
{
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 5);

    cout<<"Following the DFS (starting from vertex 0) \n";
    g.DFS(0);
    return 0;
}
*/
