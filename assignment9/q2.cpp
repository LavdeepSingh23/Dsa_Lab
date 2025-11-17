#include <iostream>
using namespace std;

// Node of adjacency list
class Node {
public:
    int vertex;
    Node* next;

    Node(int v) {
        vertex = v;
        next = NULL;
    }
};

class Graph {
public:
    int V;
    Node** adj;  // array of adjacency lists

    Graph(int n) {
        V = n;
        adj = new Node*[V];

        for(int i = 0; i < V; i++)
            adj[i] = NULL;
    }

    // Undirected graph: add edge u -- v
    void addEdge(int u, int v) {
        Node* n1 = new Node(v);
        n1->next = adj[u];
        adj[u] = n1;

        Node* n2 = new Node(u);
        n2->next = adj[v];
        adj[v] = n2;
    }

    // --------------------------------------------------------
    // DFS RECURSIVE
    // --------------------------------------------------------
    void dfsUtil(int u, int visited[]) {
        visited[u] = 1;
        cout << u << " ";

        Node* temp = adj[u];
        while(temp != NULL) {
            if(!visited[temp->vertex])
                dfsUtil(temp->vertex, visited);
            temp = temp->next;
        }
    }

    void DFS(int start) {
        int *visited = new int[V];
        for(int i = 0; i < V; i++)
            visited[i] = 0;

        cout << "DFS Traversal: ";
        dfsUtil(start, visited);
        cout << endl;

        delete[] visited;
    }
};

int main() {

    // Example graph with 5 vertices (0..4)
    Graph g(5);

    // Creating a simple undirected graph
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);

    // DFS starting from vertex 0
    g.DFS(0);

    return 0;
}
