#include <iostream>
using namespace std;

int main() {
    int arr1[] = {1, 2, 3, 4};
    int arr2[] = {3, 4, 5, 6};

    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    int mark[1000] = {0}; // simple presence array

    // Mark elements of arr1
    for (int i = 0; i < n1; i++) {
        mark[arr1[i]] = 1;
    }

    // Print those elements of arr2 which also exist in arr1
    cout << "Common Elements: ";
    for (int i = 0; i < n2; i++) {
        if (mark[arr2[i]] == 1) {
            cout << arr2[i] << " ";
        }
    }

    return 0;
}
