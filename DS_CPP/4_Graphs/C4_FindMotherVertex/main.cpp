#include <vector>
#include <list>
#include <iostream>

using namespace std;

class Graph {
private:
    int vertices;
    vector<list<int>> arr;
public:
    Graph(int vertices) : vertices{vertices}, arr{vector<list<int>>(vertices)} {}

    void addEdge(int source, int destination) {
        if(source < vertices && destination < vertices) {
            arr[source].push_front(destination);
        }
    }

    void printGraph() {
        cout << "Adjance List of Directed Graph" << endl;

        for(int i = 0; i < vertices; i++) {
            cout << "|" << i << "| = > ";
            for(auto& e : arr[i]) {
                cout << "[" << e << "] -> ";
            }
            cout << "NULL" << endl;
        } 
    }

    void DFS(int node, vector<bool>& visited) {
        visited[node] = true;

        for(auto& nbr : arr[node]) {
            if(!visited[nbr]) {
                DFS(nbr, visited);
            }
        }
    }

    int findMotherVertex() {
        vector<bool> visited(vertices, false);
        int lastV = 0;

        for(int i = 0; i < vertices; i++) {
            if(!visited[i]) {
                DFS(i, visited);
                lastV = i;
            }
        }

        visited = vector<bool>(vertices, false);

        DFS(lastV, visited);

        for(int i = 0; i < vertices; i++) {
            if(!visited[i]) {
                return -1;
            }
        }

        return lastV;
    }
};

int main() {
    Graph* g = new Graph(4);
    g->addEdge(0,1);
    g->addEdge(1,2);
    g->addEdge(3,0);
    g->addEdge(3,1);

    cout << g->findMotherVertex() <<endl;
     
}