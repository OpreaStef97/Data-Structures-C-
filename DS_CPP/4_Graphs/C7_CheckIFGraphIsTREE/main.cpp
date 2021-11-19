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
    vector<list<pair<int,int>>> adjw;
    bool undir;
    bool weighted;
public:
    Graph(int vertices) : vertices{vertices}, adj{vector<list<int>>(vertices)}, undir{false}, weighted{false} {}

    Graph(int vertices, bool undir) : Graph(vertices) {
        this->undir = undir;
    }

    Graph(int vertices, bool undir, bool weighted) {
        this->weighted = weighted;
        this->adjw = vector<list<pair<int,int>>> (vertices);
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

    void addEdge(int u, int v, int w) {
        adjw[u].push_back({v,w});
        if(undir) adjw[v].push_back({u, w});
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

    bool check_Cycle(int src, int parent, vector<bool>& visited) {
        visited[src] = true;

        for(auto& nbr : adj[src]) {
            if(!visited[nbr]) { // shortcircuit :)
                if(check_Cycle(nbr, src, visited)) {
                    return true;
                }
            }
            else if(nbr != parent) {
                return true;
            }
        }
        return false;
    }


    bool isTree() {
        vector<bool> visited(vertices, false);

        if(check_Cycle(0, -1, visited)) {
            return false;
        }

        for(int i = 0; i < vertices; i++) {
            if(!visited[i]) {
                return false;
            }
        }
        return true;
    }
};


int main() {
    Graph *g = new Graph(5,true);
    g->addEdge(1,0);
    g->addEdge(0,2);
    g->addEdge(0,3);
    g->addEdge(3,4);

    g->printGraph();

    cout << g->isTree() << endl;
}