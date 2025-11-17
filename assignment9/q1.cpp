#include <iostream>
using namespace std;

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
    Node** adj;   // array of adjacency lists

    Graph(int n) {
        V = n;
        adj = new Node*[V];

        for(int i = 0; i < V; i++)
            adj[i] = NULL;
    }

    // Add edge (undirected graph)
    void addEdge(int u, int v) {
        Node* n1 = new Node(v);
        n1->next = adj[u];
        adj[u] = n1;

        Node* n2 = new Node(u);
        n2->next = adj[v];
        adj[v] = n2;
    }

    // ----------------------------------------------------
    // Breadth First Search (using simple array queue)
    // ----------------------------------------------------
    void BFS(int start) {
        int *visited = new int[V];
        for(int i = 0; i < V; i++)
            visited[i] = 0;

        // simple array queue
        int queue[100];
        int front = 0, rear = 0;

        visited[start] = 1;
        queue[rear++] = start;

        cout << "BFS Traversal: ";

        while(front < rear) {
            int u = queue[front++];
            cout << u << " ";

            Node* temp = adj[u];
            while(temp != NULL) {
                int v = temp->vertex;
                if(!visited[v]) {
                    visited[v] = 1;
                    queue[rear++] = v;
                }
                temp = temp->next;
            }
        }

        cout << endl;

        delete[] visited;
    }
};

int main() {

    // Graph with 5 vertices (0..4)
    Graph g(5);

    // Adding edges
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);

    // BFS starting from vertex 0
    g.BFS(0);

    return 0;
}
