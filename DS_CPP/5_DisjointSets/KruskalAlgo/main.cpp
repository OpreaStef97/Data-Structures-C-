#include <vector>
#include <iostream>
#include <unordered_map>
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


class DisjointSet {
public: 
    struct Node{
        int data;
        int rank;
        Node* parent;
    };

    unordered_map<int, Node*> mp;

    void makeSet(int data) {
        Node* node = new Node();
        node->data = data;
        node->parent = node;
        node->rank = 0;
        mp[data] = node;
    }

    void Union (int data1, int data2) {
        Node* node1 = mp[data1];
        Node* node2 = mp[data2];
        
        Node* parent1 = findSet(node1);
        Node* parent2 = findSet(node2);

        if(parent1->data == parent2->data) {
            return;
        }

        if(parent1->rank >= parent2->rank) {
            parent1->rank = (parent1->rank == parent2->rank) ? 
                parent1->rank + 1 : parent2->rank;
            parent2->parent = parent1;
        }
        else {
            parent1->parent = parent2;
        }
    }

    long findSet(int data) {
        return findSet(mp[data])->data;
    }

    Node* findSet(Node* node) {
        Node* parent = node->parent;
        if(parent == node) {
            return parent;
        }
        node->parent = findSet(node->parent);
        return node->parent;
    }
};

int Graph::kruskalMST() {
    int mst_wt = 0;
    sort(edges.begin(), edges.end());

    DisjointSet ds;

    for(int i = 0; i < V; i++) {
        ds.makeSet(i);
    }

    for(auto it = edges.begin(); it != edges.end(); ++it) {
        int u = it->second.first;
        int v = it->second.second;

        int set_u = ds.findSet(u);
        int set_v = ds.findSet(v);

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
    int V = 9, E = 14;
    Graph g(V, E);
  
    //  making above shown graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
  
    cout << "Edges of MST are \n";
    int mst_wt = g.kruskalMST();
  
    cout << "\nWeight of MST is " << mst_wt;
  
    return 0;
}