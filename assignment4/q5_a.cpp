#include <iostream>
using namespace std;

class Queue {
public:
    int arr[100];
    int front, rear, size;

    Queue(int s=100) {
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

    void reset() {
        front = rear = -1;
    }
};

// ---------------------------------------------------
// STACK USING TWO QUEUES
// ---------------------------------------------------
class Stack {
public:
    Queue q1, q2;

    void push(int x) {
        // Step 1: Put new element in q2
        q2.enqueue(x);

        // Step 2: Move all old elements from q1 to q2
        while (!q1.empty()) {
            q2.enqueue(q1.dequeue());
        }

        // Step 3: Swap q1 and q2
        Queue temp = q1;
        q1 = q2;
        q2 = temp;

        cout << x << " pushed.\n";
    }

    void pop() {
        if (q1.empty()) {
            cout << "Stack empty!\n";
            return;
        }
        int val = q1.dequeue();
        cout << val << " popped.\n";
    }

    void peek() {
        if (q1.empty()) {
            cout << "Stack empty!\n";
            return;
        }
        cout << "Top element = " << q1.first() << endl;
    }

    void display() {
        if (q1.empty()) {
            cout << "Stack empty!\n";
            return;
        }
        cout << "Stack (top to bottom): ";
        for (int i = q1.front; i <= q1.rear; i++) {
            cout << q1.arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {

    Stack st;
    int choice, val;

    while (true) {
        cout << "\n--- STACK USING TWO QUEUES ---\n";
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

    return 0;
}
