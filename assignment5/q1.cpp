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

public:
    SinglyList() {
        head = NULL;
    }

    // (a) Insert at beginning
    void insertAtStart(int x) {
        Node* n = new Node(x);
        n->next = head;
        head = n;
    }

    // (b) Insert at end
    void insertAtEnd(int x) {
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

    // (c) Insert after a given value
    void insertAfter(int key, int x) {
        Node* temp = head;

        while(temp != NULL && temp->data != key)
            temp = temp->next;

        if(temp == NULL) {
            cout << "Key not found\n";
            return;
        }

        Node* n = new Node(x);
        n->next = temp->next;
        temp->next = n;
    }

    // Insert BEFORE a node
    void insertBefore(int key, int x) {
        if(head == NULL) return;

        if(head->data == key) {
            insertAtStart(x);
            return;
        }

        Node* temp = head;
        while(temp->next != NULL && temp->next->data != key)
            temp = temp->next;

        if(temp->next == NULL) {
            cout << "Key not found\n";
            return;
        }

        Node* n = new Node(x);
        n->next = temp->next;
        temp->next = n;
    }

    // (d) Delete from beginning
    void deleteStart() {
        if(head == NULL) return;

        Node* t = head;
        head = head->next;
        delete t;
    }

    // (e) Delete from end
    void deleteEnd() {
        if(head == NULL) return;

        if(head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;
        Node* prev = NULL;

        while(temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }

        prev->next = NULL;
        delete temp;
    }

    // (f) Delete a specific node
    void deleteNode(int key) {
        if(head == NULL) return;

        if(head->data == key) {
            deleteStart();
            return;
        }

        Node* temp = head;
        Node* prev = NULL;

        while(temp != NULL && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

        if(temp == NULL) {
            cout << "Node not found\n";
            return;
        }

        prev->next = temp->next;
        delete temp;
    }

    // (g) Search for a node → return position
    void search(int key) {
        Node* temp = head;
        int pos = 1;

        while(temp != NULL) {
            if(temp->data == key) {
                cout << "Node " << key << " found at position " << pos << "\n";
                return;
            }
            pos++;
            temp = temp->next;
        }

        cout << "Node not found\n";
    }

    // (h) Display all nodes
    void display() {
        Node* t = head;
        cout << "List: ";
        while(t != NULL) {
            cout << t->data << " ";
            t = t->next;
        }
        cout << endl;
    }
};

int main() {

    SinglyList s;
    int ch, val, key;

    while(1) {
        cout << "\n---- MENU ----\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert After a Value\n";
        cout << "4. Insert Before a Value\n";
        cout << "5. Delete from Beginning\n";
        cout << "6. Delete from End\n";
        cout << "7. Delete Specific Node\n";
        cout << "8. Search\n";
        cout << "9. Display\n";
        cout << "10. Exit\n";
        cout << "Enter choice: ";
        cin >> ch;

        if(ch == 10) break;

        switch(ch) {
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
                cout << "Enter node value to delete: ";
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
        }
    }

    return 0;
}

    

