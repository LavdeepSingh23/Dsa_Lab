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

class BST {
public:
    Node* root;

    BST() {
        root = NULL;
    }

    // Insert (simple)
    Node* insert(Node* r, int x) {
        if(r == NULL)
            return new Node(x);

        if(x < r->data)
            r->left = insert(r->left, x);
        else
            r->right = insert(r->right, x);

        return r;
    }

    // ==========================================================
    // (a) Search Recursive
    // ==========================================================
    Node* searchRecursive(Node* r, int key) {
        if(r == NULL || r->data == key)
            return r;

        if(key < r->data)
            return searchRecursive(r->left, key);

        return searchRecursive(r->right, key);
    }

    // ==========================================================
    // (a) Search Non-Recursive
    // ==========================================================
    Node* searchNonRecursive(int key) {
        Node* temp = root;

        while(temp != NULL) {
            if(temp->data == key)
                return temp;

            if(key < temp->data)
                temp = temp->left;
            else
                temp = temp->right;
        }

        return NULL;
    }

    // ==========================================================
    // (b) Maximum element in BST
    // ==========================================================
    int maxElement() {
        if(root == NULL) return -1;

        Node* temp = root;
        while(temp->right != NULL)
            temp = temp->right;

        return temp->data;
    }

    // ==========================================================
    // (c) Minimum element in BST
    // ==========================================================
    int minElement() {
        if(root == NULL) return -1;

        Node* temp = root;
        while(temp->left != NULL)
            temp = temp->left;

        return temp->data;
    }

    // ==========================================================
    // (d) In-order Successor
    // ==========================================================
    Node* inorderSuccessor(Node* r, int key) {
        Node* curr = searchRecursive(r, key);
        if(curr == NULL) return NULL;

        // Case 1: If right subtree exists
        if(curr->right != NULL) {
            Node* temp = curr->right;
            while(temp->left != NULL)
                temp = temp->left;
            return temp;
        }

        // Case 2: No right subtree → check ancestors
        Node* successor = NULL;
        Node* ancestor = root;

        while(ancestor != curr) {
            if(curr->data < ancestor->data) {
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else {
                ancestor = ancestor->right;
            }
        }

        return successor;
    }

    // ==========================================================
    // (e) In-order Predecessor
    // ==========================================================
    Node* inorderPredecessor(Node* r, int key) {
        Node* curr = searchRecursive(r, key);
        if(curr == NULL) return NULL;

        // Case 1: left subtree exists
        if(curr->left != NULL) {
            Node* temp = curr->left;
            while(temp->right != NULL)
                temp = temp->right;
            return temp;
        }

        // Case 2: go to ancestors
        Node* predecessor = NULL;
        Node* ancestor = root;

        while(ancestor != curr) {
            if(curr->data > ancestor->data) {
                predecessor = ancestor;
                ancestor = ancestor->right;
            }
            else {
                ancestor = ancestor->left;
            }
        }

        return predecessor;
    }

    // Just to see inorder
    void inorder(Node* r) {
        if(r == NULL) return;
        inorder(r->left);
        cout << r->data << " ";
        inorder(r->right);
    }
};

int main() {

    BST tree;

    tree.root = tree.insert(tree.root, 50);
    tree.insert(tree.root, 30);
    tree.insert(tree.root, 70);
    tree.insert(tree.root, 20);
    tree.insert(tree.root, 40);
    tree.insert(tree.root, 60);
    tree.insert(tree.root, 80);

    cout << "In-order traversal: ";
    tree.inorder(tree.root);
    cout << endl;

    // Search
    int key = 40;
    cout << "Searching " << key << " (recursive): ";
    cout << (tree.searchRecursive(tree.root, key) ? "Found\n" : "Not Found\n");

    cout << "Searching " << key << " (non-recursive): ";
    cout << (tree.searchNonRecursive(key) ? "Found\n" : "Not Found\n");

    // Min & Max
    cout << "Minimum element: " << tree.minElement() << endl;
    cout << "Maximum element: " << tree.maxElement() << endl;

    // Successor
    Node* suc = tree.inorderSuccessor(tree.root, 50);
    if(suc) cout << "In-order Successor of 50: " << suc->data << endl;
    else cout << "No Successor\n";

    // Predecessor
    Node* pre = tree.inorderPredecessor(tree.root, 50);
    if(pre) cout << "In-order Predecessor of 50: " << pre->data << endl;
    else cout << "No Predecessor\n";

    return 0;
}
