#include<bits/stdc++.h>

using namespace std;

// This class represents a directed graph using adjacency list representation
class Graph {

    int V;  // No. of vertexes
    // Pointer to an array containing adjacency lists
    list<int> *adj;
    public:
        Graph(int V);

        // function to add an edge to graph
        void addEdge(int v, int w);

        // prints BFS traversal from a given source s
        void BFS(int s);
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V]; // V number of elements in the adjacency list
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

void Graph::BFS(int s){ // s = source
    // Mark all the vertexes as not visited
    bool *visited = new bool[V];
    for(int i=0;i<V;i++){
        visited[i] = false;
    }
    // Create a queue for BFS
    list<int> queue;

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);

    // 'itr' will be used to get all adjacent vertexes of a vertex
    list<int>::iterator itr;

    while(!queue.empty()){
        // Dequeue a vertex from queue and print it
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        // Get all adjacent vertexes of the dequeued
        // vertex s. If an adjacent has not been visited,
        // then mark it visited and enqueue it
        for (itr = adj[s].begin(); itr != adj[s].end(); ++itr){
            if (!visited[*itr]){
                visited[*itr] = true;
                queue.push_back(*itr);
            }
        }
    }
}

int main()
{
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 5);

    cout<<"Following the BFS (starting from vertex 0) \n";
    g.BFS(0);

    return 0;
}
