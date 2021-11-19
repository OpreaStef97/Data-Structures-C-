#include "../BST.cpp"
#include <stack>

string findAncestors(Node *root, int k) {
    stack<Node*> ancestores;
    
    while(root && (root->value != k)) {
        ancestores.push(root);
        
        if(root->value > k) {
            root = root->left;
        }else{
            root = root->right;
        }
    }
    string res;
    while(ancestores.size()) {
        int temp = ancestores.top()->value;
        ancestores.pop();
        res += to_string(temp);
    }
    return res;
}


int main() {
    BinarySearchTree* bs = new BinarySearchTree();
    bs->insertBST(6);
    bs->insertBST(4);
    bs->insertBST(9);
    bs->insertBST(2);
    bs->insertBST(5);
    bs->insertBST(8);
    bs->insertBST(12);
    bs->insertBST(10);
    bs->insertBST(14);

    bs->levelOrderTraversal();  

    cout << findAncestors(bs->getRoot(), 10) << endl;

}