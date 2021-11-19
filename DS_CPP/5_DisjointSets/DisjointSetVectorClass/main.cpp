#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct DisjointSet {
    vector<int> parent;
    vector<int> rank;
    int n;

    DisjointSet(int n) {
        this->n = n;
        parent = vector<int>(n);
        rank = vector<int>(n);

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

    //Union by rank
    void Union(int x, int y) {
        x = find(x);
        y = find(y);

        if(rank[x] > rank[y]) {
            parent[y] = x;
        }
        else {
            parent[x] = y;
        }

        if(rank[x] == rank[y]) {
            rank[x] ++;
        }
    }

    int getRank(int data) {
        return rank[data];
    }    
};

int main() {
    int n = 8;
    DisjointSet* ds = new DisjointSet(n);

    ds->Union(1,2);
    ds->Union(2,3);
    ds->Union(4,5);
    ds->Union(6,7);
    ds->Union(5,6);
    ds->Union(3,7);

    cout << ds->getRank(4) << endl;

    for(auto r : ds->rank) {
        cout << r << ' ';
    }

    return 0;
}