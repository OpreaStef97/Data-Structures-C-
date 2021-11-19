#include <vector>
#include <list>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class Graph {
private:
    int vertices;
    vector<list<int>> arr;
    bool undir;
public:
    Graph(int vertices) : vertices{vertices}, arr{vector<list<int>>(vertices)}, undir{false} {}

    Graph(int vertices, bool undir) : Graph(vertices) {
        this->undir = undir;
    }

    void addEdge(int source, int destination) {
        if(source < vertices && destination < vertices) {
            arr[source].push_back(destination);
            if(undir) {
                arr[destination].push_back(source);
            }
        }
    }

    void printGraph() {
        cout << "Adjance List of Directed Graph" << endl;

        for(int i = 0; i < vertices; i++) {
            cout << "|" << i << "| => ";
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

    vector<int> bfsTraversal (int source);
    vector<int> dfsTraversal_Stack (int source);

    void dfs(int source, vector<bool>& visited, vector<int>& result);
    vector<int> dfsTraversal (int source);

};

vector<int> Graph::bfsTraversal (int source) {
    vector<bool> visited(vertices, false);
    vector<int> result;
    queue<int> Q;
    
    Q.push(source);
    visited[source] = true;

    while(!Q.empty()) {
        int curr_node = Q.front();
        Q.pop();
        result.push_back(curr_node);
        
        for(auto& nbr : arr[curr_node]){
            if(!visited[nbr]) {
                Q.push(nbr);
                visited[nbr] = true;
            }
        }
    }
    return result; 
}


void Graph::dfs(int source, vector<bool>& visited, vector<int>& result) {
    visited[source] = true;

    result.push_back(source);

    for(auto& nbr : arr[source]) {
        if(!visited[nbr]){
            dfs(nbr, visited, result);
        }
    }
}

vector<int> Graph::dfsTraversal(int source) {
    vector<bool>visited(vertices, false);
    vector<int> result;

    dfs(source, visited, result);

    return result;
}

vector<int> Graph::dfsTraversal_Stack (int source) {
    vector<bool> visited(vertices, false);
    vector<int> result;
    stack<int> S;
    visited[source] = true;
    S.push(source);
    while(!S.empty()) {
        int curr_node = S.top();
        result.push_back(curr_node);
        S.pop();

        for(auto& nbr : arr[curr_node]) {
            if(!visited[nbr]) {
                visited[nbr] = true;
                S.push(nbr);
            }
        }
    }

    return result;
}


int main() {
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 6);

    cout << "BFS Traversal: " << endl;
    for(auto& e : g.bfsTraversal(0)) {
        cout << e << ' ';
    }
    cout << endl << endl;

    g.printGraph();

    cout << endl << "DFS Traversal: " << endl;
    for(auto& e : g.dfsTraversal(0)) {
        cout << e << ' ';
    }


    cout << endl << "DFS Traversal with Stack: " << endl;
    for(auto& e : g.dfsTraversal_Stack(0)) {
        cout << e << ' ';
    }
    return 0;
}