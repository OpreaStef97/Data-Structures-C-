#include <iostream>
#include <array>
#include <algorithm>
#include <string>
#include <vector>

#define ALPHABET_SIZE 26

using namespace std;

class TrieNode {
public:
    array<TrieNode*, ALPHABET_SIZE> nodes;
    bool isEndWord;

    TrieNode() {
        this->isEndWord = false;
        fill(nodes.begin(), nodes.end(), nullptr);
    }
    void markAsLeaf() {
        this->isEndWord = true;
    }
    void unMarkAsLeaf() {
        this->isEndWord = false;
    }

    ~TrieNode() {
        for(auto& n : nodes) {
            delete n;
        }
    }

};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }

    Trie(vector<string> key) : Trie() {
        for(const auto& k : key) {
            this->insertNode(k);
        }
    }

    TrieNode* getRoot() {
        return root;
    }

    int getIndex(char t) {
        return t - 'a';
    }

    void insertNode(string key) {
        if(key.empty()) {
            return;
        }
        transform(key.begin(), key.end(), key.begin(), ::tolower);
        TrieNode* currNode = root;

        int idx = 0;
        for(auto& c : key) {
            idx = getIndex(c);
            if(currNode->nodes[idx] == nullptr) {
                currNode->nodes[idx] = new TrieNode();
            }
            currNode = currNode->nodes[idx];
        }
        currNode->markAsLeaf();
        cout << "'" << key << "' inserted" << endl;
    }

    bool searchNode(string key) {
        if(key.empty()) {
            return false;
        }
        transform(key.begin(), key.end(), key.begin(), ::tolower);

        TrieNode* currNode = root;

        int idx = 0;
        for(auto& c : key) {
            idx = getIndex(c);
            if(currNode->nodes[idx] == nullptr) {
                return false;
            }
            currNode = currNode->nodes[idx];
        }

        if(currNode != nullptr && currNode->isEndWord) {
            return true;
        }
        return false;
    }

    bool hasNoChildren(TrieNode* currNode) {
        for(int i = 0; i < ALPHABET_SIZE; ++i) {
            if((currNode->nodes[i]) != nullptr) {
                return false;
            }
        }
        return true;
    }

    bool deleteHelper(string key, TrieNode* currNode, int length, int lvl) {
        bool deletedSelf = false;

        if(currNode == nullptr) {
            cout << "Key does not exist\n";
            return deletedSelf;
        }

        // Base case: If we have reached the node which points to the letter at the end of the key
        if(lvl == length) {
            if(hasNoChildren(currNode)) {
                delete currNode;
                currNode = NULL;
                deletedSelf = true;
            }
            else {
                currNode->unMarkAsLeaf();
                deletedSelf = false;
            }
        }
        else {
            TrieNode* childNode = currNode->nodes[getIndex(key[lvl])];
            bool childDeleted = deleteHelper(key, childNode, length, lvl + 1);
            if(childDeleted) {
                //Making children pointer also null: since child is deleted
                currNode->nodes[getIndex(key[lvl])] = nullptr;

                //If currNode is leaf node that means currNode is part of another key
                if(currNode->isEndWord) {
                    deletedSelf = false;
                }
                //If childNode is deleted but if currNode has more children then currNode must be part of another key
                else if (!hasNoChildren(currNode)) {
                    deletedSelf = false;
                }
                else {
                    delete currNode;
                    currNode = nullptr;
                    deletedSelf = true;
                }
            }
            else {
                deletedSelf = false;
            }
        }
        return deletedSelf;
    }

    void deleteNode(string key) {
        if((root == nullptr) || (key.empty())) {
            cout << "Null key or Empty Trie ERROR\n";
            return;
        }
        deleteHelper(key, root, key.length(), 0);
    }
};