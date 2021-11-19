#include <iostream>
#include <vector>

using namespace std;

void merge(int s, int e, vector<pair<int,pair<int,int>>>& arr) {
    int i = s;
    int mid = (s + e)/2;
    int j = mid + 1;

    vector<pair<int,pair<int,int>>> temp;

    while(i <= mid && j <= e) {
        if(arr[i] < arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
        }
    }

    while(i <= mid) {
        temp.push_back(arr[i++]);
    }

    while(j <= e) {
        temp.push_back(arr[j++]);
    }

    int k = 0;
    for(int i = s; i <= e; i++) {
        arr[i] = temp[k++];
    }
}


void mergesort(int s, int e, vector<pair<int,pair<int,int>>>& arr) {
    if(s >= e) {
        return;
    }
    
    int mid = (s + e)/2;
    mergesort(s, mid, arr);
    mergesort(mid + 1, e, arr);
    merge(s, e, arr);
}


struct Graph{
    int V;
    vector<pair<int,pair<int,int>>> edges;

    Graph(int V) {
        this->V = V;
    }

    void addEdge(int u, int v, int w) {
        edges.push_back({w,{u,v}});
    }

    int KruskalMST();
};

struct DisjointSet{
    vector<int> rank;
    vector<int> parent;
    int n;

    DisjointSet(int n) {
        this->n = n;
        this->rank = vector<int>(n);
        this->parent = vector<int>(n);
        for(int i = 0; i < n; i++) {
            rank[i] = 0;
            parent[i] = i;
        }
    }

    int find(int u) {
        if(u != parent[u]) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
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

int Graph::KruskalMST() {
    mergesort(0, edges.size() - 1, edges);

    int mst_wt = 0;
    DisjointSet* ds = new DisjointSet(V);

    auto it = edges.begin();

    for( ; it != edges.end(); ++it) {
        int u = it->second.first;
        int v = it->second.second;

        int set_u = ds->find(u);
        int set_v = ds->find(v);

        if(set_u != set_v) {
            cout << u << ' ' << v << endl;
            mst_wt += it->first;

            ds->Union(set_u, set_v);
        }
    }
    return mst_wt;
}


int main() {

    Graph *g = new Graph(5);

    g->addEdge(0, 1, 1);
    g->addEdge(0, 2, 2);
    g->addEdge(1, 2, 3);
    g->addEdge(1, 4, 2);
    g->addEdge(1, 3, 8);
    g->addEdge(2, 3, 6);
    g->addEdge(3, 4, 4);

    cout << g->KruskalMST() << endl;
}