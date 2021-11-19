#include "../BST.cpp"
#include <stack>

// void inorder(Node* root, vector<int>& vec) {
//     if(!root) {
//         return;
//     }

//     inorder(root->left, vec);
//     vec.push_back(root->value);
//     inorder(root->right, vec);

// }

// int findKthMax(Node* root, int k, vector<int>& vec) {
//     inorder(root, vec);

//     return vec[vec.size()-k];
// }

int findKthMax(Node* root, int k) {
    stack<Node*> st;

    while(true) {
        while(root != nullptr) {
            st.push(root);
            root = root->right;
        }
        root = st.top();
        st.pop();
        --k;
        if(k == 0) {
            return root->value;
        }
        root = root->left;
    }
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

    cout << findKthMax(bs->getRoot(), 3);
}