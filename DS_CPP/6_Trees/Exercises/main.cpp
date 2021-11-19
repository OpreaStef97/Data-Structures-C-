#include "../BST.cpp"
#include <list>

int kthSmallest(Node* root, int k) {
    list<Node*> stack;
    
    while(true) {
        while(root != nullptr) {
            stack.push_back(root);
            root = root->left;
        }
        
        root = stack.back();
        stack.pop_back();
        --k;
        if(k == 0) {
            return root->value;
        }
        root = root->right;
    }
}


int main() {
    BinarySearchTree* bs = new BinarySearchTree();

    bs->insertBST_Rec(20);
    bs->insertBST_Rec(10);
    bs->insertBST_Rec(25);
    bs->insertBST_Rec(8);
    bs->insertBST_Rec(15);
    bs->insertBST_Rec(22);
    bs->insertBST_Rec(27);

    bs->levelOrderTraversal();

    cout << kthSmallest(bs->getRoot(), 3) << endl;
}