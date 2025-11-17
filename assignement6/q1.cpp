#include<iostream>
using namespace std;

// -------------------------------------------------------------
// A simple Node class for both doubly and circular linked lists
// -------------------------------------------------------------
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

// =====================================================================
//                          DOUBLY LINKED LIST
// =====================================================================

class DoublyList {
private:
    Node* head;

public:
    DoublyList() {
        head = NULL;
    }

    // Insert at beginning
    void insertAtStart(int x) {
        Node* n = new Node(x);

        if(head == NULL) {
            head = n;
            return;
        }

        n->next = head;
        head->prev = n;
        head = n;
    }

    // Insert at end
    void insertAtEnd(int x) {
        Node* n = new Node(x);

        if(head == NULL) {
            head = n;
            return;
        }

        Node* temp = head;
        while(temp->next != NULL) temp = temp->next;

        temp->next = n;
        n->prev = temp;
    }

    // Insert after a value
    void insertAfter(int key, int x) {
        Node* temp = head;

        while(temp != NULL && temp->data != key)
            temp = temp->next;

        if(temp == NULL) {
            cout << "Key not found.\n";
            return;
        }

        Node* n = new Node(x);
        n->next = temp->next;
        n->prev = temp;

        if(temp->next != NULL)
            temp->next->prev = n;

        temp->next = n;
    }

    // Insert before a value
    void insertBefore(int key, int x) {
        if(head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        if(head->data == key) {
            insertAtStart(x);
            return;
        }

        Node* temp = head;
        while(temp != NULL && temp->data != key)
            temp = temp->next;

        if(temp == NULL) {
            cout << "Key not found.\n";
            return;
        }

        Node* n = new Node(x);
        Node* p = temp->prev;

        n->next = temp;
        n->prev = p;

        p->next = n;
        temp->prev = n;
    }

    // Search a node
    bool search(int key) {
        Node* temp = head;
        while(temp != NULL) {
            if(temp->data == key) return true;
            temp = temp->next;
        }
        return false;
    }

    // Delete a node
    void deleteNode(int key) {
        if(head == NULL) return;

        // deleting first node
        if(head->data == key) {
            Node* t = head;
            head = head->next;
            if(head) head->prev = NULL;
            delete t;
            return;
        }

        Node* temp = head;
        while(temp != NULL && temp->data != key)
            temp = temp->next;

        if(temp == NULL) {
            cout << "Node not found.\n";
            return;
        }

        Node* p = temp->prev;
        Node* n = temp->next;

        p->next = n;
        if(n) n->prev = p;

        delete temp;
    }

    void display() {
        cout << "Doubly List: ";
        Node* temp = head;
        while(temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

// =====================================================================
//                        CIRCULAR LINKED LIST
// =====================================================================

class CircularList {
private:
    Node* head;

public:
    CircularList() {
        head = NULL;
    }

    // Insert at start
    void insertAtStart(int x) {
        Node* n = new Node(x);

        if(head == NULL) {
            head = n;
            n->next = head;
            return;
        }

        Node* temp = head;
        while(temp->next != head) temp = temp->next;

        temp->next = n;
        n->next = head;
        head = n;
    }

    // Insert at end
    void insertAtEnd(int x) {
        Node* n = new Node(x);

        if(head == NULL) {
            head = n;
            n->next = head;
            return;
        }

        Node* temp = head;
        while(temp->next != head) temp = temp->next;

        temp->next = n;
        n->next = head;
    }

    // Insert after a key
    void insertAfter(int key, int x) {
        if(head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        do {
            if(temp->data == key) {
                Node* n = new Node(x);
                n->next = temp->next;
                temp->next = n;
                return;
            }
            temp = temp->next;
        } while(temp != head);

        cout << "Key not found.\n";
    }

    // Insert before a key
    void insertBefore(int key, int x) {
        if(head == NULL) {
            cout << "List empty.\n";
            return;
        }

        // before head
        if(head->data == key) {
            insertAtStart(x);
            return;
        }

        Node* temp = head;
        do {
            if(temp->next->data == key) {
                Node* n = new Node(x);
                n->next = temp->next;
                temp->next = n;
                return;
            }
            temp = temp->next;
        } while(temp != head);

        cout << "Key not found.\n";
    }

    // Search
    bool search(int key) {
        if(head == NULL) return false;

        Node* temp = head;
        do {
            if(temp->data == key) return true;
            temp = temp->next;
        } while(temp != head);

        return false;
    }

    // Delete node
    void deleteNode(int key) {
        if(head == NULL) return;

        Node* temp = head;

        // If head is the node
        if(head->data == key) {
            if(head->next == head) {
                delete head;
                head = NULL;
                return;
            }
            Node* last = head;
            while(last->next != head) last = last->next;

            last->next = head->next;
            Node* t = head;
            head = head->next;
            delete t;
            return;
        }

        // Searching in middle
        Node* prev = NULL;
        do {
            if(temp->data == key) {
                prev->next = temp->next;
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;
        } while(temp != head);

        cout << "Node not found.\n";
    }

    void display() {
        if(head == NULL) {
            cout << "Circular List is empty.\n";
            return;
        }

        Node* temp = head;
        cout << "Circular List: ";
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while(temp != head);
        cout << "(head)\n";
    }
};

// =====================================================================
//                               MENU
// =====================================================================

int main() {
    DoublyList dl;
    CircularList cl;

    int mainChoice, op, val, key;

    while(true) {
        cout << "\n--- MAIN MENU ---\n";
        cout << "1. Doubly Linked List\n";
        cout << "2. Circular Linked List\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> mainChoice;

        if(mainChoice == 3) break;

        cout << "\n1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert After Key\n";
        cout << "4. Insert Before Key\n";
        cout << "5. Delete Node\n";
        cout << "6. Search Node\n";
        cout << "Enter operation: ";
        cin >> op;

        cout << "Enter value: ";
        cin >> val;

        if(op == 3 || op == 4 || op == 5 || op == 6) {
            cout << "Enter key: ";
            cin >> key;
        }

        // ==================== DOUBLY LIST ======================
        if(mainChoice == 1) {
            if(op == 1) dl.insertAtStart(val);
            else if(op == 2) dl.insertAtEnd(val);
            else if(op == 3) dl.insertAfter(key, val);
            else if(op == 4) dl.insertBefore(key, val);
            else if(op == 5) dl.deleteNode(key);
            else if(op == 6) {
                if(dl.search(key)) cout << "Found\n";
                else cout << "Not Found\n";
                continue;
            }

            dl.display();
        }

        // ==================== CIRCULAR LIST ====================
        else if(mainChoice == 2) {
            if(op == 1) cl.insertAtStart(val);
            else if(op == 2) cl.insertAtEnd(val);
            else if(op == 3) cl.insertAfter(key, val);
            else if(op == 4) cl.insertBefore(key, val);
            else if(op == 5) cl.deleteNode(key);
            else if(op == 6) {
                if(cl.search(key)) cout << "Found\n";
                else cout << "Not Found\n";
                continue;
            }

            cl.display();
        }
    }

    return 0;
}
