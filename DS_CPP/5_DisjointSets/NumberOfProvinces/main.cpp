#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    struct DisjointSet {
        vector<int> parent;
        vector<int> rank;
        int n;
        
        DisjointSet(int n) {
            this->n = n;
            this->rank = vector<int>(n, 0);
            this->parent = vector<int>(n);
            for(int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        int find(int u) {
            if(u != parent[u]) {
                parent[u] = find(parent[u]);
            }
            return parent[u];
        }

        void Union (int u, int v) {
            int x = find(u);
            int y = find(v);

            if(rank[x] < rank[y]) {
                parent[x] = y;
            } 
            rank[x]++;
            parent[y] = x;
        }
    };
    int findCircleNum(vector<vector<int>>& isConnected) {

        DisjointSet* ds = new DisjointSet(isConnected.size());
        for(int i = 0; i < (int)isConnected.size(); i++) {
            for(int j = i + 1; j < (int)isConnected.size(); j ++) {
                if(isConnected[i][j] == 1 && i != j) {
                    ds->Union(i,j);
                }
            }
        }
        int groups = 0;
        for(int i = 0; i < (int)isConnected.size(); i++) {
            if(ds->parent[i] == i) {
                groups++;
            }
        }

        delete ds;
        return groups;
    }
};


int main() {
    vector<vector<int>> adjMatrix = {
        {1,1,0},
        {1,1,0},
        {0,0,1},
    };

    Solution* s = new Solution();
    cout << s->findCircleNum(adjMatrix) << endl;

}