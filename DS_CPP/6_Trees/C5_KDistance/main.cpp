#include "../BST.cpp"


string findKNodes(Node* root, int k) {
    queue<Node*> q;
    q.push(root);
    string res = "";
    int level = 0;
    while(!q.empty()) {
        string str;
        int n = q.size();
        for(int i = 0; i < n; ++i) {
            Node* temp = q.front(); q.pop();
            str += to_string(temp->value) + ",";

            if(temp->left) {
                q.push(temp->left);
            }
            if(temp->right) {
                q.push(temp->right);
            } 
        }
        if(level == k) {
            res += str;
            break;
        }
        level++;
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

    cout << findKNodes(bs->getRoot(), 2) << endl;

}