#include "../Trie.hpp"
#include <unordered_map>

bool isFormationPossible(Trie* T, TrieNode* root, string word){
  // Write your code here

    TrieNode* currNode = root;

    for(int i = 0; i < (int)word.size(); ++i) {
        int idx = word[i] - 'a';

        if(currNode->nodes[idx] == nullptr) {
            return false;
        }
        else if(currNode->nodes[idx]->isEndWord == true && T->searchNode(word.substr(i+1))) {
            return true;
        }
        currNode = currNode->nodes[idx];
    }
    return false;
}


int main() {

    vector<string> keys = {"apple", "pen"};

    Trie* trie = new Trie(keys);

    TrieNode* root = trie->getRoot();

    string word = "applepen";
    cout << isFormationPossible(trie, root, word) << endl;

    return 0;
}