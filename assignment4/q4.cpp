#include <iostream>
using namespace std;

class Queue {
public:
    char arr[100];
    int front, rear;

    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(char x) {
        if (rear == 99) return;
        if (front == -1) front = 0;
        arr[++rear] = x;
    }

    void dequeue() {
        if (front == -1 || front > rear) return;
        front++;
    }

    bool empty() {
        return (front == -1 || front > rear);
    }

    char first() {
        if (!empty()) return arr[front];
        return '#';
    }
};

int main() {

    char s[100];
    cout << "Enter characters (no spaces, e.g. aabc): ";
    cin >> s;

    int freq[256] = {0};
    Queue q;

    cout << "\nOutput: ";

    for (int i = 0; s[i] != '\0'; i++) {

        char c = s[i];
        freq[c]++;

        q.enqueue(c);

        // Remove repeated characters from front of queue
        while (!q.empty() && freq[q.first()] > 1) {
            q.dequeue();
        }

        // Output
        if (q.empty())
            cout << "-1 ";
        else
            cout << q.first() << " ";
    }

    cout << endl;
    return 0;
}
