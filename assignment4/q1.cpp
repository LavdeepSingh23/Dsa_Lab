#include <iostream>
using namespace std;

class Queue {
public:
    int arr[100];
    int front, rear, size;

    Queue(int s) {
        size = s;
        front = -1;
        rear = -1;
    }

    // Enqueue
    void enqueue(int x) {
        if (rear == size - 1) {
            cout << "Queue Overflow! Cannot insert " << x << endl;
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = x;
        cout << x << " enqueued.\n";
    }

    // Dequeue
    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow! Nothing to delete.\n";
            return;
        }
        cout << arr[front] << " dequeued.\n";
        front++;
    }

    // Peek
    void peek() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Front element: " << arr[front] << endl;
    }

    // Display
    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Check empty directly (no function)
    void checkEmpty() {
        if (front == -1 || front > rear)
            cout << "Queue is EMPTY.\n";
        else
            cout << "Queue is NOT empty.\n";
    }

    // Check full directly (no function)
    void checkFull() {
        if (rear == size - 1)
            cout << "Queue is FULL.\n";
        else
            cout << "Queue is NOT full.\n";
    }
};

int main() {

    int s;
    cout << "Enter queue size: ";
    cin >> s;

    Queue q(s);
    int ch, val;

    while (true) {
        cout << "\n--- QUEUE MENU ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. isEmpty\n";
        cout << "4. isFull\n";
        cout << "5. Display\n";
        cout << "6. Peek\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> val;
                q.enqueue(val);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.checkEmpty();
                break;

            case 4:
                q.checkFull();
                break;

            case 5:
                q.display();
                break;

            case 6:
                q.peek();
                break;

            case 7:
                cout << "Exiting program.\n";
                return 0;

            default:
                cout << "Invalid choice, try again.\n";
        }
    }
}
