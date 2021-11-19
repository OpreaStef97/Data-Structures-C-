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
};