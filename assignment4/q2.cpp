#include <iostream>
using namespace std;

class CircularQueue {
public:
    int arr[100];
    int front, rear, size;

    CircularQueue(int s) {
        size = s;
        front = -1;
        rear = -1;
    }

    // ENQUEUE
    void enqueue(int x) {
        if ((front == 0 && rear == size - 1) || (rear + 1) % size == front) {
            cout << "Queue is FULL! Cannot enqueue " << x << endl;
            return;
        }

        if (front == -1) {  // first element
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }

        arr[rear] = x;
        cout << x << " enqueued.\n";
    }

    // DEQUEUE
    void dequeue() {
        if (front == -1) {
            cout << "Queue is EMPTY! Nothing to dequeue.\n";
            return;
        }

        cout << arr[front] << " dequeued.\n";

        if (front == rear) {  
            // only one element present
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
    }

    // PEEK
    void peek() {
        if (front == -1) {
            cout << "Queue is EMPTY!\n";
            return;
        }
        cout << "Front element: " << arr[front] << endl;
    }

    // DISPLAY
    void display() {
        if (front == -1) {
            cout << "Queue is EMPTY!\n";
            return;
        }

        cout << "Circular Queue: ";
        int i = front;

        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size;
        }
        cout << endl;
    }

    // Check EMPTY directly
    void checkEmpty() {
        if (front == -1)
            cout << "Queue is EMPTY.\n";
        else
            cout << "Queue is NOT empty.\n";
    }

    // Check FULL directly
    void checkFull() {
        if ((front == 0 && rear == size - 1) || (rear + 1) % size == front)
            cout << "Queue is FULL.\n";
        else
            cout << "Queue is NOT full.\n";
    }
};

int main() {
    int s;
    cout << "Enter circular queue size: ";
    cin >> s;

    CircularQueue q(s);
    int choice, val;

    while (true) {
        cout << "\n--- CIRCULAR QUEUE MENU ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. isEmpty\n";
        cout << "4. isFull\n";
        cout << "5. Display\n";
        cout << "6. Peek\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

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
            cout << "Exiting program...\n";
            return 0;

        default:
            cout << "Invalid choice, try again.\n";
        }
    }

    return 0;
}
