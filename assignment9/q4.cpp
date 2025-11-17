#include <iostream>
using namespace std;

#define INF 999999

class Graph {
public:
    int V;
    int adj[20][20];

    Graph(int n) {
        V = n;
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                adj[i][j] = 0;
            }
        }
    }

    void addEdge(int u, int v, int wt) {
        adj[u][v] = wt;     // directed graph
        // adj[v][u] = wt;  // uncomment for undirected
    }

    // ------------------------------------------------------
    // Dijkstra's Shortest Path Algorithm
    // ------------------------------------------------------
    void dijkstra(int src) {

        int dist[20];
        int visited[20];

        for(int i = 0; i < V; i++) {
            dist[i] = INF;
            visited[i] = 0;
        }

        dist[src] = 0;

        for(int c = 0; c < V - 1; c++) {

            // Pick the unvisited node with minimum distance
            int u = -1;
            for(int i = 0; i < V; i++) {
                if(!visited[i] && (u == -1 || dist[i] < dist[u]))
                    u = i;
            }

            visited[u] = 1;

            // Relax edges from u
            for(int v = 0; v < V; v++) {
                if(adj[u][v] && !visited[v]) {
                    if(dist[u] + adj[u][v] < dist[v]) {
                        dist[v] = dist[u] + adj[u][v];
                    }
                }
            }
        }

        // Print result
        cout << "Shortest distances from source " << src << ":\n";
        for(int i = 0; i < V; i++) {
            cout << "To " << i << " : " << dist[i] << endl;
        }
    }
};

int main() {

    int V = 5;
    Graph g(V);

    // Sample weighted graph
    g.addEdge(0, 1, 10);
    g.addEdge(0, 4, 5);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 4, 2);
    g.addEdge(2, 3, 4);
    g.addEdge(3, 0, 7);
    g.addEdge(3, 2, 6);
    g.addEdge(4, 1, 3);
    g.addEdge(4, 2, 9);
    g.addEdge(4, 3, 2);

    // Dijkstra from source node 0
    g.dijkstra(0);

    return 0;
}
