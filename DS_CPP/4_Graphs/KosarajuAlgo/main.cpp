#include <vector>
#include <list>
#include <iostream>
#include <stack>

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

    void printDFS(int node, vector<bool>& visited) {
        visited[node] = true;
        cout << node << ' ';
        for(auto& c : arr[node]) {
            if(!visited[c]) {
                printDFS(c, visited);
            }
        }
    }

    Graph getTranspose() {
        Graph g(vertices);
        for(int v = 0; v < vertices; v++) {
            for(auto& u : arr[v]) {
                g.arr[u].push_back(v);
            }
        }
        return g;
    }

    void fillOrderDFS(int v, vector<bool>& visited, stack<int>& Stack) {
        visited[v] = true;

        for(auto& nbr : arr[v]) {
            if(!visited[nbr]) {
                fillOrderDFS(nbr, visited, Stack);
            }
        }

        Stack.push(v);
    }

    void printSCC() {
        stack<int> Stack;

        vector<bool> visited (vertices, false);

        for(int i = 0; i < vertices; i++) {
            if(!visited[i]) {
                fillOrderDFS(i,visited,Stack);
            }
        }

        Graph gr = this->getTranspose();

        visited = vector<bool> (vertices, false);

        while(!Stack.empty()) {
            int v = Stack.top(); Stack.pop();

            if(!visited[v]) {
                gr.printDFS(v, visited);
                cout << endl;
            }
        }
    }


};


int main()
{
    // Create a graph given in the above diagram
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);
    
    g.printGraph();

    g.printSCC();
  
    return 0;
}