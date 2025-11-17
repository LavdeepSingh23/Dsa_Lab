#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* next;
    Node* prev;

    Node(char c) {
        data = c;
        next = NULL;
        prev = NULL;
    }
};

class DoublyList {
private:
    Node* head;

public:
    DoublyList() {
        head = NULL;
    }

    // Insert char at end
    void insertEnd(char c) {
        Node* n = new Node(c);

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

    // Check palindrome
    bool isPalindrome() {
        if(head == NULL || head->next == NULL)
            return true;

        Node* left = head;
        Node* right = head;

        // Move right to the last node
        while(right->next != NULL)
            right = right->next;

        // Compare from both ends
        while(left != right && right->next != left) {
            if(left->data != right->data)
                return false;

            left = left->next;
            right = right->prev;
        }

        return true;
    }

    void display() {
        Node* t = head;
        while(t != NULL) {
            cout << t->data << " ";
            t = t->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyList dl;

    // Example list
    dl.insertEnd('R');
    dl.insertEnd('A');
    dl.insertEnd('D');
    dl.insertEnd('A');
    dl.insertEnd('R');

    cout << "List: ";
    dl.display();

    if(dl.isPalindrome())
        cout << "The list is a palindrome.\n";
    else
        cout << "The list is NOT a palindrome.\n";

    return 0;
}
