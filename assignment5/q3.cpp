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

    // insert at end
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

    // Find middle using slow & fast pointers
    int findMiddle() {
        if (head == NULL)
            return -1;

        Node* slow = head;
        Node* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;          // moves 1 step
            fast = fast->next->next;    // moves 2 steps
        }

        return slow->data;   // slow is at the middle
    }
};

int main() {

    LinkedList list;

    // building list: 1 -> 2 -> 3 -> 4 -> 5
    list.insertEnd(1);
    list.insertEnd(2);
    list.insertEnd(3);
    list.insertEnd(4);
    list.insertEnd(5);

    cout << "The middle element is: " << list.findMiddle() << endl;

    return 0;
}
