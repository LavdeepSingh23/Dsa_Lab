#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class CircularList {
private:
    Node* head;

public:
    CircularList() {
        head = NULL;
    }

    // Insert at end (simple)
    void insertAtEnd(int x) {
        Node* n = new Node(x);

        if(head == NULL) {
            head = n;
            n->next = head;
            return;
        }

        Node* temp = head;
        while(temp->next != head)
            temp = temp->next;

        temp->next = n;
        n->next = head;
    }

    // Display and repeat head value at the end
    void displayWithRepeat() {
        if(head == NULL) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;

        // Print normally
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while(temp != head);

        // Print head again
        cout << head->data << endl;
    }
};

int main() {
    CircularList cl;

    // Input: 20 → 100 → 40 → 80 → 60
    cl.insertAtEnd(20);
    cl.insertAtEnd(100);
    cl.insertAtEnd(40);
    cl.insertAtEnd(80);
    cl.insertAtEnd(60);

    // Expected Output: 20 100 40 80 60 20
    cl.displayWithRepeat();

    return 0;
}
