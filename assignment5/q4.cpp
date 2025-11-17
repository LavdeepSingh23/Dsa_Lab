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

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    void insertEnd(int x) {
        Node* n = new Node(x);
        if (head == NULL) {
            head = n;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = n;
    }

    // Reverse the linked list (iterative)
    void reverse() {
        Node* prev = NULL;
        Node* curr = head;
        Node* nextNode = NULL;

        while (curr != NULL) {
            nextNode = curr->next;  // store next node
            curr->next = prev;      // reverse the link
            prev = curr;            // move prev forward
            curr = nextNode;        // move curr forward
        }
        head = prev;  // new head
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {

    LinkedList list;

    // Input: 1 -> 2 -> 3 -> 4 -> NULL
    list.insertEnd(1);
    list.insertEnd(2);
    list.insertEnd(3);
    list.insertEnd(4);

    cout << "Original List: ";
    list.display();

    list.reverse();

    cout << "Reversed List: ";
    list.display();

    return 0;
}
