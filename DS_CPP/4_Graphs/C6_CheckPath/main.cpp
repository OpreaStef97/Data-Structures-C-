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

    int numEdges() {
        vector<bool> visited(vertices, false);
        int sum = 0;
        for(int i = 0; i < vertices; i++) {
            for(auto it = adj[i].begin(); it != adj[i].end(); it++) {
                sum++;
            }
        }
        return sum/2;
    }

    void DFS(int src, vector<bool>& visited) {
        visited[src] = true;

        for(auto& nbr : adj[src]) {
            if(!visited[nbr]) {
                DFS(nbr, visited);
            }
        }
    }

    bool checkPath(int source, int destination) {
        vector<bool> visited(vertices, false);

        DFS(source, visited);
        
        return visited[destination];
    }

};

int main() {
    Graph* g = new Graph(9);

    g->addEdge(0,2);
    g->addEdge(0,5);
    g->addEdge(2,3);
    g->addEdge(2,4);
    g->addEdge(5,3);
    g->addEdge(5,6);
    g->addEdge(3,6);
    g->addEdge(6,7);
    g->addEdge(6,8);
    g->addEdge(6,4);
    g->addEdge(7,8);

    g->printGraph();

    cout << boolalpha << g->checkPath(5,7);
}