#include <iostream>
#include <vector>
#include <memory>

using namespace std;

struct DisjointSet {
    vector<int> parent;
    vector<int> rank;
    int n;

    DisjointSet(int n) {
        this->n = n;
        this->rank = vector<int>(n, 0);
        this->parent = vector<int>(n);

        for(int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int data) {
        if(data != parent[data]) {
            parent[data] = find(parent[data]);
        }
        return parent[data];
    }

    void Union(int u, int v) {
        int x = find(u);
        int y = find(v);

        if(rank[x] > rank[y]) {
            parent[y] = x;
        }
        else if(rank[x] < rank[y]) {
            parent[x] = y;
        }
        else {
            rank[x]++;
            parent[y] = x;
        } 
    }
};

class Graph {
public:
    int V;
    vector<pair<int,int>> edges;
    
    Graph(int V) {
        this->V = V;
    }

    void addEdge(int u, int v) {
        edges.push_back({u,v});
    }

    bool isCycle() {
        unique_ptr<DisjointSet> ds(new DisjointSet(V));

        for(auto& e : edges) {
            int u = e.first;
            int v = e.second;

            int set_u = ds->find(u);
            int set_v = ds->find(v);

            if(set_u != set_v) {
                ds->Union(set_u, set_v);
            } else {
                return true;
            }
        }
        return false;
    }

};


 
// Driver code
int main() {

    int V = 3;

    unique_ptr<Graph> g(new Graph(V));

    g->addEdge(0,1);
    g->addEdge(1,2);
    g->addEdge(2,0);

    cout << boolalpha << g->isCycle() << endl;
}