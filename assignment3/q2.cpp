#include <iostream>
using namespace std;

class Stack {
public:
    char arr[100];
    int top;

    Stack() {
        top = -1;
    }

    void push(char c) {
        arr[++top] = c;
    }

    char pop() {
        return arr[top--];
    }

    bool isEmpty() {
        return top == -1;
    }
};

int main() {

    char str[100];
    cout << "Enter a string: ";
    cin >> str;

    Stack s;

    // Push all characters onto the stack
    for (int i = 0; str[i] != '\0'; i++) {
        s.push(str[i]);
    }

    // Pop all characters to reverse
    cout << "Reversed string: ";
    while (!s.isEmpty()) {
        cout << s.pop();
    }

    cout << endl;

    return 0;
}
