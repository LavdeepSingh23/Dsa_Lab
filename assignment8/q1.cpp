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

// ----------------------------
// Pre-order traversal
// ----------------------------
void preorder(Node* root) {
    if(root == NULL) return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// ----------------------------
// In-order traversal
// ----------------------------
void inorder(Node* root) {
    if(root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// ----------------------------
// Post-order traversal
// ----------------------------
void postorder(Node* root) {
    if(root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// Main
// ----------------------------
int main() {

    // Creating a simple binary tree manually
    //         10
    //       /    \
    //     20      30
    //    /  \
    //   40  50

    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);

    cout << "Pre-Order : ";
    preorder(root);
    cout << endl;

    cout << "In-Order : ";
    inorder(root);
    cout << endl;

    cout << "Post-Order: ";
    postorder(root);
    cout << endl;

    return 0;
}
