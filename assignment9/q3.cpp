#include <iostream>
using namespace std;

// =======================================================
//                 STRUCT FOR EDGES (For Kruskal)
// =======================================================
class Edge {
public:
    int src, dest, wt;
};

// =======================================================
//                UNION-FIND (For Kruskal)
// =======================================================
int findParent(int v, int parent[]) {
    if(parent[v] == v)
        return v;
    return parent[v] = findParent(parent[v], parent); // path compression
}

void unionSet(int a, int b, int parent[], int rank[]) {
    a = findParent(a, parent);
    b = findParent(b, parent);

    if(a != b) {
        if(rank[a] < rank[b])
            parent[a] = b;
        else if(rank[a] > rank[b])
            parent[b] = a;
        else {
            parent[b] = a;
            rank[a]++;
        }
    }
}

// =======================================================
//               KRUSKAL'S ALGORITHM
// =======================================================
void kruskalMST(Edge edges[], int E, int V) {

    // sort edges by weight (simple bubble sort)
    for(int i = 0; i < E-1; i++) {
        for(int j = 0; j < E-i-1; j++) {
            if(edges[j].wt > edges[j+1].wt) {
                Edge temp = edges[j];
                edges[j] = edges[j+1];
                edges[j+1] = temp;
            }
        }
    }

    int parent[100], rank[100];

    for(int i = 0; i < V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    cout << "\nMinimum Spanning Tree using Kruskal:\n";

    int count = 0;   // edges in MST
    int i = 0;       // edge index

    while(count < V-1 && i < E) {
        Edge curr = edges[i];

        int p1 = findParent(curr.src, parent);
        int p2 = findParent(curr.dest, parent);

        if(p1 != p2) {
            cout << curr.src << " -- " << curr.dest << "  wt=" << curr.wt << "\n";
            unionSet(p1, p2, parent, rank);
            count++;
        }
        i++;
    }
}

// =======================================================
//               PRIM'S ALGORITHM (Adj. Matrix)
// =======================================================
void primMST(int graph[10][10], int V) {

    int key[10];
    int parent[10];
    int mstSet[10];

    for(int i = 0; i < V; i++) {
        key[i] = 99999;     // infinity
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for(int cnt = 0; cnt < V-1; cnt++) {

        int u = -1;

        // Pick min key vertex not yet included
        for(int i = 0; i < V; i++) {
            if(!mstSet[i] && (u == -1 || key[i] < key[u]))
                u = i;
        }

        mstSet[u] = 1;

        for(int v = 0; v < V; v++) {
            if(graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "\nMinimum Spanning Tree using Prim:\n";
    for(int i = 1; i < V; i++) {
        cout << parent[i] << " -- " << i << "  wt=" << graph[i][parent[i]] << "\n";
    }
}

// =======================================================
//                         MAIN
// =======================================================
int main() {

    int V = 5;   // number of vertices
    int E = 7;   // number of edges

    // -------------------------
    // Example edges for Kruskal
    // -------------------------
    Edge edges[] = {
        {0,1,2}, {0,3,6}, {1,2,3}, {1,3,8},
        {1,4,5}, {2,4,7}, {3,4,9}
    };

    // Run Kruskal
    kruskalMST(edges, E, V);

    // -------------------------
    // Example adjacency matrix for Prim
    // -------------------------
    int graph[10][10] = {
        {0,2,0,6,0},
        {2,0,3,8,5},
        {0,3,0,0,7},
        {6,8,0,0,9},
        {0,5,7,9,0}
    };

    // Run Prim
    primMST(graph, V);

    return 0;
}
