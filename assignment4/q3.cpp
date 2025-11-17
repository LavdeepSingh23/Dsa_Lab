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
            cout << "Queue is full.\n";
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = x;
    }

    int dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue empty.\n";
            return -1;
        }
        return arr[front++];
    }

    bool empty() {
        return (front == -1 || front > rear);
    }

    void display() {
        if (empty()) {
            cout << "Queue empty.\n";
            return;
        }
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {

    Queue q;
    int n;

    cout << "Enter number of elements (even number): ";
    cin >> n;

    cout << "Enter " << n << " queue elements:\n";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.enqueue(x);
    }

    // Step 1: Move first half into a temporary queue
    int half = n / 2;
    Queue firstHalf;

    for (int i = 0; i < half; i++) {
        int val = q.dequeue();
        firstHalf.enqueue(val);
    }

    // Step 2: Interleave
    Queue result;

    while (!firstHalf.empty()) {
        int a = firstHalf.dequeue();
        int b = q.dequeue();

        result.enqueue(a);
        result.enqueue(b);
    }

    // Step 3: Output result
    cout << "Interleaved Queue: ";
    result.display();

    return 0;
}
