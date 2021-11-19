#include "../BST.cpp"

int findHeight(Node* root) {
    if(!root) {
        return -1;
    }

    int leftH = findHeight(root->left);
    int rightH = findHeight(root->right);

    return max(leftH, rightH) + 1;
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

    cout << findHeight(bs->getRoot()) << endl;

}