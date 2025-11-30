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

class SinglyList {
private:
    Node* head;
    Node* tail;

public:
    SinglyList() {
        head = NULL;
        tail = NULL;
    }

    // (a) Insert at beginning
    void insertAtStart(int x) {
        Node* newnode = new Node(x);

        if (head == NULL) {  
            head = tail = newnode;
            return;
        }

        newnode->next = head;
        head = newnode;
    }

    // (b) Insert at end
    void insertAtEnd(int x) {
        Node* newnode = new Node(x);

        if (head == NULL) {
            head = tail = newnode;
            return;
        }

        tail->next = newnode;
        tail = newnode;
    }

    // (c) Insert AFTER a given value
    void insertAfter(int key, int x) {
        Node* temp = head;

        while (temp != NULL && temp->data != key)
            temp = temp->next;

        if (temp == NULL) {
            cout << "Key not found\n";
            return;
        }

        Node* newnode = new Node(x);
        newnode->next = temp->next;
        temp->next = newnode;

        if (temp == tail)  
            tail = newnode;
    }

    // Insert BEFORE a node
    void insertBefore(int key, int x) {
        if (head == NULL) return;

        if (head->data == key) {
            insertAtStart(x);
            return;
        }

        Node* temp = head;

        while (temp->next != NULL && temp->next->data != key)
            temp = temp->next;

        if (temp->next == NULL) {
            cout << "Key not found\n";
            return;
        }

        Node* newnode = new Node(x);
        newnode->next = temp->next;
        temp->next = newnode;
    }

    // (d) Delete from beginning
    void deleteStart() {
        if (head == NULL) return;

        Node* t = head;
        head = head->next;

        if (head == NULL) tail = NULL;

        delete t;
    }

    // (e) Delete from end
    void deleteEnd() {
        if (head == NULL) return;

        Node* temp = head;

        while(temp ->next != tail){
            temp = temp->next;
        }
        temp ->next = NULL;
        delete tail;
        tail = temp;
    }

    // (f) Delete specific node
    void deleteNode(int key) {
        if (head == NULL) return;

        if (head->data == key) {
            deleteStart();
            return;
        }

        Node* temp = head;

        while (temp->next != NULL && temp->next->data != key)
            temp = temp->next;

        Node* toDel = temp->next;
        temp->next = temp->next->next;

        if (toDel == tail)
            tail = temp;

        delete toDel;
    }

    // (g) Search
    void search(int key) {
        Node* temp = head;
        int pos = 1;

        while (temp != NULL) {
            if (temp->data == key) {
                cout << "Node " << key << " found at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }

        cout << "Node not found\n";
    }

    // (h) Display list
    void display() {
        Node* t = head;

        cout << "List: ";
        while (t != NULL) {
            cout << t->data << " ";
            t = t->next;
        }
        cout << endl;
    }
};

// ===============================================================

int main() {

    SinglyList s;
    int ch, val, key;

    while (1) {
        cout << "\n---- MENU ----\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert After a Value\n";
        cout << "4. Insert Before a Value\n";
        cout << "5. Delete from Beginning\n";
        cout << "6. Delete from End\n";
        cout << "7. Delete Specific Node\n";
        cout << "8. Search Node\n";
        cout << "9. Display List\n";
        cout << "10. Exit\n";
        cout << "Enter choice: ";
        cin >> ch;

        if (ch == 10) break;

        switch (ch) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                s.insertAtStart(val);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> val;
                s.insertAtEnd(val);
                break;

            case 3:
                cout << "Enter value to insert: ";
                cin >> val;
                cout << "Insert after which node? ";
                cin >> key;
                s.insertAfter(key, val);
                break;

            case 4:
                cout << "Enter value to insert: ";
                cin >> val;
                cout << "Insert before which node? ";
                cin >> key;
                s.insertBefore(key, val);
                break;

            case 5:
                s.deleteStart();
                break;

            case 6:
                s.deleteEnd();
                break;

            case 7:
                cout << "Enter value to delete: ";
                cin >> key;
                s.deleteNode(key);
                break;

            case 8:
                cout << "Enter value to search: ";
                cin >> key;
                s.search(key);
                break;

            case 9:
                s.display();
                break;

            default:
                cout << "Invalid choice!\n";
        }
    }

    return 0;
}
