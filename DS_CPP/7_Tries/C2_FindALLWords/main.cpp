#include "../Trie.hpp"


void findWords(TrieNode* CurrNode, string word, vector<string>& result) {
    if(CurrNode->isEndWord) {
        result.push_back(word);
    }

    for(int i = 0; i < 26; ++i) {
        if(CurrNode->nodes[i] != nullptr) {
            word.push_back(i + 'a');
            findWords(CurrNode->nodes[i], word, result);
            word.pop_back();
        }
    }
}

vector<string> findWords(TrieNode * root) {
    vector<string> result;
    TrieNode* CurrNode = root;

    findWords(CurrNode, "", result);

    return result;
}

int main() {
    vector<string> keys = {"a","abc", "answer", "any", "by", "bye", "the", "there", "their"};

    Trie* T = new Trie(keys);
    
    TrieNode* root = T->getRoot();
    
    for(auto& s : findWords(root)) {
        cout << s << endl;
    }
}