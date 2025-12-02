#include <iostream>
using namespace std;

int main() {
    int arr[] = {4, 5, 1, 2, 0, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int countArr[1000] = {0};

    // Count frequency
    for (int i = 0; i < n; i++) {
        countArr[arr[i]]++;
    }

    // Find the first element with frequency = 1
    for (int i = 0; i < n; i++) {
        if (countArr[arr[i]] == 1) {
            cout << "First non-repeating element: " << arr[i];
            return 0;
        }
    }

    cout << "No unique element found";
    return 0;
}
