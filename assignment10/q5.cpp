#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

bool detectLoop(Node* head) {
    Node* visited[1000] = {nullptr};
    int idx = 0;

    Node* curr = head;

    while (curr != nullptr) {
        for (int i = 0; i < idx; i++) {
            if (visited[i] == curr) {
                return true; // loop found
            }
        }
        visited[idx++] = curr;
        curr = curr->next;
    }

    return false; // no loop
}

int main() {
    Node* a = new Node{1, nullptr};
    Node* b = new Node{2, nullptr};
    Node* c = new Node{3, nullptr};
    Node* d = new Node{4, nullptr};

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = b; // loop created

    if (detectLoop(a))
        cout << "Loop Present";
    else
        cout << "No Loop";

    return 0;
}
