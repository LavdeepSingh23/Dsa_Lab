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

    // Insert at end just to build list easily
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

    // Count occurrences of key
    int countOccurrences(int key) {
        int cnt = 0;
        Node* temp = head;

        while (temp != NULL) {
            if (temp->data == key)
                cnt++;
            temp = temp->next;
        }
        return cnt;
    }

    // Delete ALL occurrences of key
    void deleteAllOccurrences(int key) {
        // Case 1: Delete from head repeatedly
        while (head != NULL && head->data == key) {
            Node* t = head;
            head = head->next;
            delete t;
        }

        // Case 2: Delete in-between
        Node* curr = head;
        Node* prev = NULL;

        while (curr != NULL) {
            if (curr->data == key) {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }
            else {
                prev = curr;
                curr = curr->next;
            }
        }
    }

    // Display list
    void display() {
        Node* temp = head;
        if (!temp) {
            cout << "List is empty.\n";
            return;
        }
        while (temp != NULL) {
            cout << temp->data;
            if (temp->next) cout << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {

    LinkedList list;

    // Building example list: 1 -> 2 -> 1 -> 2 -> 1 -> 3 -> 1
    list.insertEnd(1);
    list.insertEnd(2);
    list.insertEnd(1);
    list.insertEnd(2);
    list.insertEnd(1);
    list.insertEnd(3);
    list.insertEnd(1);

    cout << "Original List: ";
    list.display();

    int key = 1;

    // Count occurrences
    int count = list.countOccurrences(key);
    cout << "Occurrences of " << key << " = " << count << endl;

    // Delete all occurrences
    list.deleteAllOccurrences(key);

    cout << "List after deleting all occurrences of " << key << ": ";
    list.display();

    return 0;
}
