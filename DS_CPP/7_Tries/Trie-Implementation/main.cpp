#include "../Trie.hpp"

int main() {

    const int n = 9;

    array<string, n> keys = {"the", "there"};

    Trie* t = new Trie();

    for(const auto& k : keys) {
        t->insertNode(k);
    }
    
    cout << t->searchNode("there") << endl;
    
    t->deleteNode("there");

    cout << t->searchNode("there") << endl;
    cout << t->searchNode("the") << endl;

    return 0;
}