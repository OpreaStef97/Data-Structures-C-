#include <vector>
#include <list>
#include <iostream>

using namespace std;

class Graph {
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

    int getVertices() {
        return vertices;
    }

    vector<list<int>> getArray() {
        return arr;
    }

    bool detectCycleDFS(vector<bool>& visited, vector<bool>& recNodes, int source) {
        if(!visited[source]) {

            visited[source] = true;
            recNodes[source] = true;

            for(auto& nbr : arr[source]) {

                if(!visited[nbr] && detectCycleDFS(visited, recNodes, nbr)) {
                    return true;
                }
                else if(recNodes[nbr]) {
                    return true;
                }
            }
        }
        recNodes[source] = false;
        return false;
    }

    bool detectCycle() {
        vector<bool> visited(vertices, false);
        vector<bool> recNodes(vertices, false);
        for(int i = 0; i < vertices; i++) {
            if(detectCycleDFS(visited, recNodes, i)) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Graph g(3);

    g.addEdge(0, 1);
    g.addEdge(1, 2);

    cout << endl;
    cout << boolalpha;

    cout << g.detectCycle() << endl;
    cout << endl;
    g.printGraph();
}