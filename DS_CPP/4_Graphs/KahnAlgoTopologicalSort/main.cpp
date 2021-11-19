#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include <set>

using namespace std;

class Graph {
private:
    int vertices;
    vector<list<int>> adj;
    bool undir;
public:
    Graph(int vertices) : vertices{vertices}, adj{vector<list<int>>(vertices)}, undir{false} {}

    Graph(int vertices, bool undir) : Graph(vertices) {
        this->undir = undir;
    }

    void addEdge(int u, int v) {
        if(u < vertices && v < vertices) {
            adj[u].push_back(v);
            if(undir) {
                adj[v].push_back(u);
            }
        }
    }

    void printGraph() {
        cout << "Adjance List of Directed Graph" << endl;

        for(int i = 0; i < vertices; i++) {
            cout << "|" << i << "| = > ";
            for(auto& e : adj[i]) {
                cout << "[" << e << "] -> ";
            }
            cout << "NULL" << endl;
        } 
    }

    void topological_sort() {
        vector<int> indegree(vertices, 0);

        for(int i = 0; i < vertices; i++) {
            for(auto& nbr : adj[i]) {
                indegree[nbr]++;
            }
        }

        queue<int> Q;

        for(int i = 0; i < vertices; i++) {
            if(!indegree[i]) {
                Q.push(i);
            }
        }

        while(!Q.empty()) {
            int node = Q.front(); Q.pop();
            cout << node << ' ';

            for(auto& nbr : adj[node]) {
                indegree[nbr]--;
                if(!indegree[nbr]) {
                    Q.push(nbr);
                }
            }
        }
    }
};

int main() {
   Graph g(6);
   g.addEdge(0, 3);
   g.addEdge(1, 3);
   g.addEdge(2, 3);
   g.addEdge(3, 4);
   g.addEdge(4, 5);

   g.topological_sort();

}