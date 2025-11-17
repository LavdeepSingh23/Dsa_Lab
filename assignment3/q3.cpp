#include <iostream>
using namespace std;

int main() {

    char exp[100];
    cout << "Enter expression: ";
    cin >> exp;

    char stack[100];
    int top = -1;

    for (int i = 0; exp[i] != '\0'; i++) {

        char c = exp[i];

        // When c is an opening bracket → PUSH
        if (c == '(' || c == '{' || c == '[') {
            stack[++top] = c;
        }

        // When c is a closing bracket → POP and compare
        else if (c == ')' || c == '}' || c == ']') {

            // If stack empty while popping → unbalanced
            if (top == -1) {
                cout << "Not Balanced\n";
                return 0;
            }

            char popped = stack[top--];

            // Direct comparisons (no match() function)
            if ( (popped == '(' && c != ')') ||
                 (popped == '{' && c != '}') ||
                 (popped == '[' && c != ']') ) 
            {
                cout << "Not Balanced\n";
                return 0;
            }
        }
    }

    // After scanning entire expression, stack must be empty
    if (top == -1)
        cout << "Balanced\n";
    else
        cout << "Not Balanced\n";

    return 0;
}
