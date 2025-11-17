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
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    void insertEnd(int x) {
        Node* n = new Node(x);

        if(head == NULL) {
            head = n;
            return;
        }

        Node* temp = head;
        while(temp->next != NULL)
            temp = temp->next;

        temp->next = n;
    }

    // Make the list circular manually (for testing)
    void makeCircular() {
        if(head == NULL) return;

        Node* temp = head;
        while(temp->next != NULL)
            temp = temp->next;

        temp->next = head;  // last node points to head
    }

    // Check if the list is circular
    bool isCircular() {
        if(head == NULL) return false;

        Node* temp = head->next;

        // Traverse until we hit NULL or head again
        while(temp != NULL && temp != head)
            temp = temp->next;

        if(temp == head)
            return true;    // circular
        else
            return false;   // not circular
    }
};

int main() {
    LinkedList list;

    list.insertEnd(10);
    list.insertEnd(20);
    list.insertEnd(30);

    // Uncomment this to make it circular
    // list.makeCircular();

    if(list.isCircular())
        cout << "The linked list IS a circular linked list.\n";
    else
        cout << "The linked list is NOT circular.\n";

    return 0;
}
