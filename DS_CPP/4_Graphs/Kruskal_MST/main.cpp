#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Graph {
    int V, E;
    vector<pair<int,pair<int, int>>> edges;

    Graph(int V, int E) {
        this->V = V;
        this->E = E;
    }

    void addEdge(int u, int v, int w) {
        edges.push_back({w, {u, v}});
    }

    int kruskalMST();
};

struct DisjointSets {
    vector<int> parent;
    vector<int> rank;
    int n;

    DisjointSets(int n) {
        this->n = n;
        parent = vector<int>(n);
        rank = vector<int>(n);

        for(int i = 0; i < n; i++) {
            rank[i] = 0;
            parent[i] = i;
        }
    }

    int find(int u) {
        /* Make the parent of the nodes in the path
        from u--> parent[u] point to parent[u] */
        if(u != parent[u]) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    //Union by rank
    void Union(int x, int y) {
        x = find(x);
        y = find(y);

        if(rank[x] > rank[y]) {
            parent[y] = x;
        } 
        else if(rank[x] < rank[y]) {
            parent[x] = y;
        } 
        else {
            parent[y] = x;
            rank[x]++;
        }
    }    
};

int Graph::kruskalMST() {
    int mst_wt = 0;
    sort(edges.begin(), edges.end());

    DisjointSets ds(V);

    for(auto it = edges.begin(); it != edges.end(); ++it) {
        int u = it->second.first;
        int v = it->second.second;

        int set_u = ds.find(u);
        int set_v = ds.find(v);

        if(set_u != set_v) {
            cout << u << " - " << v << endl;

            mst_wt += it->first;

            ds.Union(set_u, set_v);
        }
    }
    return mst_wt;
    
}



int main() {
    /* Let us create above shown weighted
       and unidrected graph */
    int V = 5, E = 7;
    Graph g(V, E);
  
    //  making above shown graph
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 2);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 4, 2);
    g.addEdge(1, 3, 8);
    g.addEdge(2, 3, 6);
    g.addEdge(3, 4, 4);


  
    cout << "Edges of MST are \n";
    int mst_wt = g.kruskalMST();
  
    cout << "\nWeight of MST is " << mst_wt;
  
    return 0;
}