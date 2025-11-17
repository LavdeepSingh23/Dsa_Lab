#include <iostream>
using namespace std;

int main() {

    char exp[100];
    cout << "Enter postfix expression: ";
    cin >> exp;

    int stack[100];
    int top = -1;

    for (int i = 0; exp[i] != '\0'; i++) {

        char c = exp[i];

        // If operand → push (single digit)
        if (c >= '0' && c <= '9') {
            stack[++top] = c - '0';   // convert char to int
        }
        else {
            // c is operator → pop two operands
            int b = stack[top--];
            int a = stack[top--];

            int result;

            // Perform operation directly (no helper fn)
            if (c == '+') result = a + b;
            else if (c == '-') result = a - b;
            else if (c == '*') result = a * b;
            else if (c == '/') result = a / b;

            // Push result back
            stack[++top] = result;
        }
    }

    cout << "Result = " << stack[top] << endl;

    return 0;
}
