#include "../BST.cpp"

int Diameter(Node* root, int& d) {
    if(!root) {
        return 0;
    }

    int leftH = Diameter(root->left, d);
    int rightH = Diameter(root->right, d);

    d = max(d, leftH + rightH);
    
    return 1 + max(leftH, rightH);
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
    int d = 0;
    cout << Diameter(bs->getRoot(), d) << endl;
    cout << d << endl;
}