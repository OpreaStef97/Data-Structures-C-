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
        cout << "Adjance List of Directed Graph" << endl;

        for(int i = 0; i < vertices; i++) {
            cout << "|" << i << "| = > ";
            for(auto& e : adj[i]) {
                cout << "[" << e << "] -> ";
            }
            cout << "NULL" << endl;
        } 
    }

    void printGraphW() {
        cout << "Adjance List of Directed Graph" << endl;

        for(int i = 0; i < vertices; i++) {
            cout << "|" << i << "| = > ";
            for(auto& nbr : adjw[i]) {
                cout << "[" << "v:" << nbr.first << ", w:" << nbr.second << "] -> ";
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

    int dijkstra(int src, int end) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(vertices, numeric_limits<int> :: max());
        dist[src] = 0;
        pq.push({0,src});

        while(!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for(auto& nbr : adjw[u]) {
                int v = nbr.first;
                int w = nbr.second;

                if(dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist[end];
    }


};

int main () {
    Graph g(5, true, true);
	g.addEdge(0,1, 1);
	g.addEdge(1,2, 1);
	g.addEdge(0,2, 4);
	g.addEdge(0,3, 7);
	g.addEdge(3,2, 2);
	g.addEdge(3,4, 3);

    g.printGraphW();

    cout << g.dijkstra(0, 4) << endl;
}