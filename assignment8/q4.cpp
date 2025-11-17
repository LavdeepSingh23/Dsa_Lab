#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

// ----------------------------------------------
// Check if tree is BST using inorder traversal
// ----------------------------------------------

bool checkBST(Node* root, int& prev) {
    if(root == NULL) 
        return true;

    // left subtree
    if(!checkBST(root->left, prev))
        return false;

    // current node check
    if(root->data <= prev)
        return false;

    prev = root->data;

    // right subtree
    return checkBST(root->right, prev);
}

// Wrapper function
bool isBST(Node* root) {
    int prev = -1000000000;  // a very small number
    return checkBST(root, prev);
}

// ----------------------------------------------
// Main for testing
// ----------------------------------------------
int main() {

    // Example binary tree
    //        8
    //       / \
    //      3   10
    //     / \    \
    //    1   6    14

    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);

    root->left->left = new Node(1);
    root->left->right = new Node(6);

    root->right->right = new Node(14);

    if(isBST(root))
        cout << "The binary tree IS a BST.\n";
    else
        cout << "The binary tree is NOT a BST.\n";

    return 0;
}
