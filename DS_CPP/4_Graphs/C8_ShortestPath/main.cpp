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

    int findMin(int source, int destination) {
        vector<bool> visited(vertices, false);
        vector<int> distance(vertices, 0);
        queue<int> Q;
        visited[source] = true;
        
        Q.push(source);

        while(!Q.empty()) {
            int node = Q.front(); Q.pop();
            for(auto& nbr : adj[node]) {
                if(!visited[nbr]) {
                    visited[nbr] = true;
                    Q.push(nbr);
                    distance[nbr] = distance[node] + 1;
                }
                if(nbr == destination) {
                    return distance[destination];
                } 
            }
        }

        return -1;
    }

};

int main () {
    Graph g(6);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(0,3);
	g.addEdge(3,5);
	g.addEdge(5,4);
	g.addEdge(2,4);

    g.printGraph();

    cout << g.findMin(0,4) << endl;

}