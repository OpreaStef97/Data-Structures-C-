#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class BinarySearchTree;
class Node {
public:
    int value;
    Node* left;
    Node* right;
    Node() : value{0}, left{nullptr}, right{nullptr} {}
    Node(int val) : value{val}, left{nullptr}, right{nullptr} {};

    friend class BinarySearchTree;
};

class BinarySearchTree {
private:
    Node *root;
public:
    BinarySearchTree() : root{nullptr} {};
    BinarySearchTree(int rootValue) : root{new Node(rootValue)} {};
    Node *getRoot() {
        return root;
    }

    void insertBST(int val) {
        if(root == NULL) {
            root = new Node(val);
            return;
        }

        Node* currNode = root;
        Node* parent;

        while(currNode) {
            parent = currNode;
            if(val < currNode->value) {
                currNode = currNode->left;
            }
            else {
                currNode = currNode->right;
            }
        }
        if(val < parent->value) {
            parent->left = new Node(val);
        }
        else {
            parent->right = new Node(val);
        }
    }

    void insertBST_Rec(int val) {
        this->root = insertBSTR(this->root, val);
    }

    Node* insertBSTR(Node*root, int val) {
        if(root == nullptr) {
            return new Node(val);
        }

        if(root->value > val) {
            root->left = insertBSTR(root->left, val);
        } else {
            root->right = insertBSTR(root->right, val);
        }
        return root;
    }

    void inorderTraversal() {
        inorderTrav(getRoot());
        cout << endl;
    }
    void postorderTraversal() {
        postOrderTrav(getRoot());
        cout << endl;
    }
    void preorderTraversal() {
        preOrderTrav(getRoot());
        cout << endl;
    }

    Node* searchBST(int value) {
        Node* currNode = root;

        while(currNode && (currNode->value != value)) {
            if(value < currNode->value) {
                currNode = currNode->left;
            }
            else {
                currNode = currNode->right;
            }
        }
        return currNode;
    }

    bool Delete(int value) {
        return delete_BST(root, value);
    }

    bool DeleteRec(int value) {
        if(delete_BST_Rec(root, value)) {
            return true;
        }
        return false;
    }

private:
    bool delete_BST(Node* currNode, int value) {
        if(!root) {
            return false;
        }
        Node* parent;

        while(currNode != nullptr && (currNode->value != value)) {
            parent = currNode;
            if(currNode->value > value) {
                currNode = currNode->left;
            } 
            else {
                currNode = currNode->right;
            }
        }

        if(currNode == nullptr) {
            return false;
        }
        // 1) Node is Leaf NODE
        else if(currNode->left == nullptr && currNode->right == nullptr) {
            if(root->value == currNode->value) {
                delete root;
                root = nullptr;
                return true;
            }
            else if(currNode->value < parent->value) {
                delete parent->left;
                parent->left = nullptr;
                return true;
            }
            else {
                delete parent->right;
                parent->right = nullptr;
                return true;
            }
        }
        // 2) a) Node has only left child
        else if(currNode->right == nullptr) {
            if(root->value == currNode ->value) {
                delete root;
                root = currNode->left;
                return true;
            }
            else if(currNode->value < parent->value) {
                delete parent->left;
                parent->left = currNode->left;
                return true;
            }
            else {
                delete parent->right;
                parent->right = currNode->left;
                return true;
            }
        }
        // 2) b) Node has only right child
        else if(currNode->left == nullptr) {
            if(root->value == currNode->value) {
                delete root;
                root = currNode->right;
                return true;
            }
            else if(currNode->value < parent->value) {
                delete parent->left;
                parent->left = currNode->right;
                return true;
            }
            else {
                delete parent->right;
                parent->right = currNode->right;
                return true;
            }
        }
        // 3) Node has both childs
        else {
            Node* leastNode = findLeastNode(currNode->right);

            int tmp = leastNode->value;
            delete_BST(root, tmp);
            currNode->value = tmp;

            return true;
        }
        return false;
    }

    

    Node* delete_BST_Rec(Node* root, int value) {
        if(!root) {
            return nullptr;
        }

        if(value < root->value) {
            root->left = delete_BST_Rec(root->left, value);
        }
        else if (value > root->value) {
            root->right = delete_BST_Rec(root->right,value);
        }
        else {
            // 1) Node is Leaf Node
            if(root->left == nullptr && root->right == nullptr) {
                delete root;
                return nullptr;
            }
            // 2) Node has only one Child

            if(root->left == nullptr) {
                Node* rightSubTree = root->right;
                delete root;
                return rightSubTree;
            }

            if(root->right == nullptr) {
                Node* leftSubTree = root->left;
                delete root;
                return leftSubTree;
            }

            Node* leastNode = findLeastNode(root->right);
            swap(root->value, leastNode->value);
            root->right = delete_BST_Rec(root->right, leastNode->value);
        }
        return root;
    }

    Node* findLeastNode(Node* currNode) {
        Node* temp = currNode;
        while(temp->left != nullptr) {
            temp = temp->left;
        }
        return temp;
    }

// Traversals
    void inorderTrav(Node* root) {
        if(!root) {
            return;
        }

        inorderTrav(root->left);
        cout << root->value << ' ';
        inorderTrav(root->right);
    }

    void postOrderTrav(Node* root) {
        if(!root) {
            return;
        }

        postOrderTrav(root->left);
        postOrderTrav(root->right);
        cout << root->value << ' ';
    }

    void preOrderTrav(Node* root) {
        if(!root) {
            return;
        }
        cout << root->value << ' ';
        preOrderTrav(root->left);
        preOrderTrav(root->right);
    }
public:
    void levelOrderTraversal() {
        vector<vector<int>> result;
        levelOrder(root, result);
        for(auto&e : result) {
            for(auto& x : e) {
                cout << x << ' ';
            }
            cout << endl;
        }
    }

    void zigzaglevelOrderTraversal() {
        vector<vector<int>> result;
        zigzagLevelOrder(root, result);
        for(auto&e : result) {
            for(auto& x : e) {
                cout << x << ' ';
            }
            cout << endl;
        }
    }

private:
    void levelOrder(Node* root, vector<vector<int>>& res) {
        
        queue<Node*> Q;
        Q.push(root);
        while(!Q.empty()) {
            int n = Q.size();
            vector<int> tempVec;
            
            for(int i = 0; i < n; ++i) {
                Node* temp = Q.front(); Q.pop();
                tempVec.push_back(temp->value);
                if(temp->left) {
                    Q.push(temp->left);
                }
                if(temp->right) {
                    Q.push(temp->right);
                }
            }   
            res.push_back(tempVec);
        }
    }

    void zigzagLevelOrder(Node* root, vector<vector<int>>& res) {
        queue<Node*> Q;
        Q.push(root);
        bool level{0};
        while(!Q.empty()) {
            int n = Q.size();
            vector<int> tempVec(n);
            for(int i = 0; i < n; ++i) {
                Node* temp = Q.front(); Q.pop();
                if(!level) {
                    tempVec[i] = temp->value;
                } else {
                    tempVec[n - i - 1] = temp->value;
                }
                if(temp->left) {
                    Q.push(temp->left);
                }
                if(temp->right) {
                    Q.push(temp->right);
                }
            }
            res.push_back(tempVec);
            level = !level;
        }
    }
};

int main() {
    BinarySearchTree* bs = new BinarySearchTree();
    
    bs->insertBST_Rec(20);
    bs->insertBST_Rec(10);
    bs->insertBST_Rec(25);
    bs->insertBST_Rec(8);
    bs->insertBST_Rec(15);
    bs->insertBST_Rec(6);
    bs->insertBST_Rec(9);
    bs->insertBST_Rec(13);
    bs->insertBST_Rec(17);
    bs->insertBST_Rec(22);
    bs->insertBST_Rec(21);
    bs->insertBST_Rec(23);
    bs->insertBST_Rec(27);
    bs->insertBST_Rec(26);
    bs->insertBST_Rec(29);

    bs->inorderTraversal();
    bs->postorderTraversal();
    bs->preorderTraversal();

    if(bs->searchBST(10)) {
        cout << "Value found" << endl;
    } else {
        cout << "Value not found" << endl;
    }


    bs->DeleteRec(20);
    bs->DeleteRec(25);

    bs->levelOrderTraversal();
}