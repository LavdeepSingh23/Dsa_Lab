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

    // ===========================================
    // (a) INSERT — NO DUPLICATES
    // ===========================================
    Node* insert(Node* r, int x) {
        if(r == NULL)
            return new Node(x);

        if(x < r->data)
            r->left = insert(r->left, x);
        else if(x > r->data)
            r->right = insert(r->right, x);
        else {
            cout << "Duplicate " << x << " not inserted.\n";
        }

        return r;
    }

    // ===========================================
    // Find minimum value node (helper for delete)
    // ===========================================
    Node* findMin(Node* r) {
        while(r->left != NULL)
            r = r->left;
        return r;
    }

    // ===========================================
    // (b) DELETE NODE
    // ===========================================
    Node* deleteNode(Node* r, int key) {
        if(r == NULL)
            return r;

        if(key < r->data)
            r->left = deleteNode(r->left, key);

        else if(key > r->data)
            r->right = deleteNode(r->right, key);

        else {
            // Case 1: No child
            if(r->left == NULL && r->right == NULL) {
                delete r;
                return NULL;
            }

            // Case 2: One child
            else if(r->left == NULL) {
                Node* temp = r->right;
                delete r;
                return temp;
            }
            else if(r->right == NULL) {
                Node* temp = r->left;
                delete r;
                return temp;
            }

            // Case 3: Two children
            Node* temp = findMin(r->right);
            r->data = temp->data;
            r->right = deleteNode(r->right, temp->data);
        }

        return r;
    }

    // ===========================================
    // (c) MAXIMUM DEPTH of BST
    // ===========================================
    int maxDepth(Node* r) {
        if(r == NULL) return 0;

        int left = maxDepth(r->left);
        int right = maxDepth(r->right);

        return (left > right ? left : right) + 1;
    }

    // ===========================================
    // (d) MINIMUM DEPTH of BST
    // ===========================================
    int minDepth(Node* r) {
        if(r == NULL) 
            return 0;

        // leaf node
        if(r->left == NULL && r->right == NULL)
            return 1;

        // if left is NULL, go right
        if(r->left == NULL)
            return minDepth(r->right) + 1;

        // if right is NULL, go left
        if(r->right == NULL)
            return minDepth(r->left) + 1;

        // both children exist
        int left = minDepth(r->left);
        int right = minDepth(r->right);

        return (left < right ? left : right) + 1;
    }

    // simple inorder to see the tree
    void inorder(Node* r) {
        if(r == NULL) return;
        inorder(r->left);
        cout << r->data << " ";
        inorder(r->right);
    }
};

int main() {

    BST tree;

    // Insert some sample values
    tree.root = tree.insert(tree.root, 50);
    tree.insert(tree.root, 30);
    tree.insert(tree.root, 70);
    tree.insert(tree.root, 20);
    tree.insert(tree.root, 40);
    tree.insert(tree.root, 60);
    tree.insert(tree.root, 80);

    cout << "In-order Traversal: ";
    tree.inorder(tree.root);
    cout << endl;

    // Delete a node
    cout << "Deleting 20...\n";
    tree.root = tree.deleteNode(tree.root, 20);

    cout << "In-order After Deletion: ";
    tree.inorder(tree.root);
    cout << endl;

    // Max & Min depth
    cout << "Maximum Depth of BST = " << tree.maxDepth(tree.root) << endl;
    cout << "Minimum Depth of BST = " << tree.minDepth(tree.root) << endl;

    return 0;
}
