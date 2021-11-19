#include "../Trie.hpp"

int totalWords(TrieNode* root) {
    int result = 0;

    if(root->isEndWord) {
        result++;
    }

    for(int i = 0; i < 26; ++i) {
        if(root->nodes[i]){
            result += totalWords(root->nodes[i]);
        }
    }
    return result;
}


int main() {
    vector<string> keys = {"a","abc", "answer", "any", "by", "bye", "the", "there", "their"};

    Trie* T = new Trie(keys);
    
    TrieNode* root = T->getRoot();

    cout << totalWords(root) << endl;

}