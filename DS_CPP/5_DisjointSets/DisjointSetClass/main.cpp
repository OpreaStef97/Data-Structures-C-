#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class DisjointSet {
public: 
    struct Node{
        int data;
        int rank;
        Node* parent;
    };

    unordered_map<int, Node*> mp;

    void makeSet(int data) {
        Node* node = new Node();
        node->data = data;
        node->parent = node;
        node->rank = 0;
        mp[data] = node;
    }

    void Union (int data1, int data2) {
        Node* node1 = mp[data1];
        Node* node2 = mp[data2];
        
        Node* parent1 = findSet(node1);
        Node* parent2 = findSet(node2);

        if(parent1->data == parent2->data) {
            return;
        }

        if(parent1->rank > parent2->rank) {
            parent2->parent = parent1;
        }
        else if(parent1->rank < parent2->rank) {
            parent1->parent = parent2;
        }

        if(parent1->rank == parent2->rank) {
            parent1->rank++;
            parent2->parent = parent1;
        }
    }

    long findSet(int data) {
        return findSet(mp[data])->data;
    }

    Node* findSet(Node* node) {
        Node* parent = node->parent;
        if(parent == node) {
            return parent;
        }
        node->parent = findSet(node->parent);
        return node->parent;
    }

    int getRank(int data) {
        return mp[data]->rank;
    }
};

int main() {
    DisjointSet* ds = new DisjointSet();
    ds->makeSet(1);
    ds->makeSet(2);
    ds->makeSet(3);
    ds->makeSet(4);
    ds->makeSet(5);
    ds->makeSet(6);
    ds->makeSet(7);

    ds->Union(1,2);
    ds->Union(2,3);
    ds->Union(4,5);
    ds->Union(6,7);
    ds->Union(5,6);
    ds->Union(3,7);

    ds->makeSet(11);
    ds->makeSet(12);
    ds->makeSet(13);
    ds->makeSet(14);

    ds->Union(11,12);
    ds->Union(11,13);
    ds->Union(14,12);

    cout<< ds->getRank(4) << endl;

    delete ds;
}