#include <iostream>
using namespace std;

class Stack {
    int arr[100];
    int top;
    int size;

public:
    Stack(int s) {
        top = -1;
        size = s;
    }

    // (i) PUSH
    void push(int x) {
        if (top == size - 1) {   // Direct check instead of isFull()
            cout << "Stack Overflow! Cannot push " << x << endl;
            return;
        }
        arr[++top] = x;
        cout << x << " pushed.\n";
    }

    // (ii) POP
    void pop() {
        if (top == -1) {         // Direct check instead of isEmpty()
            cout << "Stack Underflow! Nothing to pop.\n";
            return;
        }
        cout << arr[top--] << " popped.\n";
    }

    // (vi) PEEK
    void peek() {
        if (top == -1) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Top element: " << arr[top] << endl;
    }

    // (v) DISPLAY
    void display() {
        if (top == -1) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Stack (top to bottom): ";
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }

    // Extra: check empty/full (no extra functions, only direct print)
    void checkEmpty() {
        if (top == -1) cout << "Stack is EMPTY.\n";
        else cout << "Stack is NOT empty.\n";
    }

    void checkFull() {
        if (top == size - 1) cout << "Stack is FULL.\n";
        else cout << "Stack is NOT full.\n";
    }
};

int main() {
    int size;
    cout << "Enter size of stack: ";
    cin >> size;

    Stack st(size);
    int choice, val;

    while (true) {
        cout << "\n--- STACK MENU ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. isEmpty\n";
        cout << "4. isFull\n";
        cout << "5. Display\n";
        cout << "6. Peek\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                st.push(val);
                break;

            case 2:
                st.pop();
                break;

            case 3:
                st.checkEmpty();
                break;

            case 4:
                st.checkFull();
                break;

            case 5:
                st.display();
                break;

            case 6:
                st.peek();
                break;

            case 7:
                cout << "Exiting program.\n";
                return 0;

            default:
                cout << "Invalid choice.\n";
        }
    }
}
