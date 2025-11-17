#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

// =====================================================
//                 DOUBLY LINKED LIST
// =====================================================

class DoublyList {
private:
    Node* head;

public:
    DoublyList() {
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
        n->prev = temp;
    }

    // Count number of nodes
    int size() {
        int cnt = 0;
        Node* temp = head;

        while(temp != NULL) {
            cnt++;
            temp = temp->next;
        }

        return cnt;
    }
};

// =====================================================
//                 CIRCULAR LINKED LIST
// =====================================================

class CircularList {
private:
    Node* head;

public:
    CircularList() {
        head = NULL;
    }

    void insertEnd(int x) {
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

    // Count nodes in circular list
    int size() {
        if(head == NULL) return 0;

        int cnt = 0;
        Node* temp = head;

        do {
            cnt++;
            temp = temp->next;
        } while(temp != head);

        return cnt;
    }
};

// =====================================================
//                       MAIN
// =====================================================

int main() {

    DoublyList dl;
    CircularList cl;

    // Adding some values
    dl.insertEnd(10);
    dl.insertEnd(20);
    dl.insertEnd(30);

    cl.insertEnd(5);
    cl.insertEnd(15);
    cl.insertEnd(25);
    cl.insertEnd(35);

    cout << "Size of Doubly Linked List = " << dl.size() << endl;
    cout << "Size of Circular Linked List = " << cl.size() << endl;

    return 0;
}
