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
        this->vertices = vertices;
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
        adjw[u].push_back({v, w});
        if(undir) adjw[v].push_back({u, w});
    }

    void printGraph() {
        if(!undir) {
            cout << "Adjance List of Directed Graph" << endl;
        }
        else {
            cout << "Adjance List of Undirected Graph" << endl;
        }
        for(int i = 0; i < vertices; i++) {
            cout << "|" << i << "| = > ";
            for(auto& e : adj[i]) {
                cout << "[" << e << "] -> ";
            }
            cout << "NULL" << endl;
        } 
    }

    void printGraphW() {
        cout << "Adjance List of Weighted Graph" << endl;

        for(int i = 0; i < vertices; i++) {
            cout << "|" << i << "| = > ";
            for(auto& nbr : adjw[i]) {
                cout << "[" << "v:" << nbr.first << ", w:" << nbr.second << "] -> ";
            }
            cout << "NULL" << endl;
        } 
    }

    void removeEdge(int source, int destination){
        
        for(auto it = adj[source].begin(); it != adj[source].end(); ++it) {
            if(*it == destination) {
                adj[source].erase(it);
                break;
            }
        }
    }
};

int main () {
    Graph g(5);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(1,3);
    g.addEdge(2,3);
	g.addEdge(2,4);
	g.addEdge(4,0);

    g.printGraph();

    g.removeEdge(2, 3);

    g.printGraph();

}