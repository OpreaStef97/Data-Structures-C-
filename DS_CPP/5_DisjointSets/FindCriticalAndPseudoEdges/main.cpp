#include <vector>
#include <iostream>
#include <algorithm>
#include <memory>
#include <map>

using namespace std;

struct DisjointSet {
    vector<int> rank,parent;
    int n;
    
    DisjointSet(int n) {
        this->n = n;
        this->rank = vector<int>(n);
        this->parent = vector<int>(n);
        for(int i = 0; i < n; ++i) {
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
    
    void Union(int x, int y) {
        x = find(x);
        y = find(y);
        
        if(rank[x] > rank[y]) parent[y] = x;
        else if(rank[x] < rank[y]) parent[x] = y;
        else {
            ++rank[x];
            parent[y] = x;
        }
    }
};

class Solution {
public:
    int MST(int n, vector<vector<int>>& edges, vector<int>& include, vector<int>& exclude) {
        DisjointSet* ds = new DisjointSet(n);
        int mst_w = 0;

        if(include.size() != 0) {
            if(ds->find(include[0]) != ds->find(include[1])) {
                ds->Union(include[0], include[1]);
                mst_w += include[2];
            }
        }

        for(auto &e : edges) {
            if(exclude != e) {
                int u = e[0];
                int v = e[1];

                int set_u = ds->find(u);
                int set_v = ds->find(v);

                if(set_u != set_v) {
                    mst_w += e[2];
                    ds->Union(set_u, set_v);
                } 
            }
        }

        for(int i = 0; i < n; i++) {
            //means when all are not connected so return
            if(ds->find(i) != ds->find(0))
                return 1e5;
        }

        return mst_w;
    }
    
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        map<vector<int>,int> mp;

        for(int i = 0; i < (int)edges.size(); i++) {
            mp[edges[i]] = i;
        }


        sort(edges.begin(), edges.end(), [&] (vector<int>& x, vector<int>& y) {
            return (x[2] < y[2]);
        });
        vector<int> temp;

        int mst_w = MST(n, edges, temp, temp);

        vector<int> critical, noncritical;


        for(int i = 0; i < (int)edges.size(); i++) {

            if(mst_w < MST(n ,edges, temp, edges[i])) {

                critical.push_back(mp[edges[i]]);

            } else if (mst_w == MST(n, edges, edges[i], temp)) {
                
                noncritical.push_back(mp[edges[i]]);
                
            }
        }
        vector<vector<int>> result;

        result.push_back(critical);
        result.push_back(noncritical);

        return result;
    }
};

int main() {
    vector<vector<int>> edges = {
        {0,1,1},
        {1,2,1},
        {2,3,2},
        {0,3,2},
        {0,4,3},
        {3,4,3},
        {1,4,6},
    };

    unique_ptr<Solution> s (new Solution());
    
    for(auto& e : s->findCriticalAndPseudoCriticalEdges(5, edges)) {
        for(auto& x : e) {
            cout << x << ' ';
        }
        cout << endl; 
    }

    return 0;
}

