#include <iostream>
using namespace std;

class Queue {
public:
    int arr[100];
    int front, rear, size;

    Queue(int s = 100) {
        size = s;
        front = -1;
        rear = -1;
    }

    void enqueue(int x) {
        if (rear == size - 1) {
            cout << "Queue full.\n";
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = x;
    }

    int dequeue() {
        if (front == -1 || front > rear) {
            return -1;
        }
        return arr[front++];
    }

    bool empty() {
        return (front == -1 || front > rear);
    }

    int first() {
        return arr[front];
    }

    int countElements() {
        if (empty()) return 0;
        return rear - front + 1;
    }

    void resetIfNeeded() {
        if (front > rear) front = rear = -1;
    }
};


// ---------------------------------------------------
// STACK USING ONE QUEUE
// ---------------------------------------------------
class Stack {
public:
    Queue q;

    void push(int x) {
        int count = q.countElements();

        // Step 1: Push new element
        q.enqueue(x);

        // Step 2: Rotate previous elements
        while (count--) {
            int val = q.dequeue();
            q.enqueue(val);
        }

        cout << x << " pushed.\n";
    }

    void pop() {
        if (q.empty()) {
            cout << "Stack empty!\n";
            return;
        }
        cout << q.dequeue() << " popped.\n";
        q.resetIfNeeded();
    }

    void peek() {
        if (q.empty()) {
            cout << "Stack empty!\n";
            return;
        }
        cout << "Top element = " << q.first() << endl;
    }

    void display() {
        if (q.empty()) {
            cout << "Stack empty!\n";
            return;
        }
        cout << "Stack (top to bottom): ";
        for (int i = q.front; i <= q.rear; i++)
            cout << q.arr[i] << " ";
        cout << endl;
    }
};


// ---------------------------------------------------
// MAIN MENU
// ---------------------------------------------------
int main() {

    Stack st;
    int choice, val;

    while (true) {
        cout << "\n--- STACK USING ONE QUEUE ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            st.push(val);
            break;

        case 2:
            st.pop();
            break;

        case 3:
            st.peek();
            break;

        case 4:
            st.display();
            break;

        case 5:
            cout << "Exiting...\n";
            return 0;

        default:
            cout << "Invalid choice!\n";
        }
    }
}
