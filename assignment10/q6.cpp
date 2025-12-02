#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Check duplicates using hash set
bool containsDuplicate(Node* root, unordered_set<int>& used) {
    if (root == nullptr)
        return false;

    // Duplicate found
    if (used.count(root->data))
        return true;

    // store value
    used.insert(root->data);

    // check both children
    return containsDuplicate(root->left, used) || 
           containsDuplicate(root->right, used);
}

int main() {
    Node* root = new Node{1, nullptr, nullptr};
    root->left = new Node{2, nullptr, nullptr};
    root->right = new Node{3, nullptr, nullptr};
    root->left->left = new Node{4, nullptr, nullptr};
    root->right->left = new Node{2, nullptr, nullptr}; // duplicate

    unordered_set<int> visited;

    if (containsDuplicate(root, visited))
        cout << "Duplicate Found";
    else
        cout << "No Duplicate";

    return 0;
}
