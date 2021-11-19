#include "../BST.cpp"


int findMinNode(Node* root) {
    Node* currNode = root;
    Node* parent;

    while(currNode) {
        parent = currNode;
        currNode = currNode->left;
    }

    return parent->value;
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

    cout << findMinNode(bs->getRoot()) << endl;
}
