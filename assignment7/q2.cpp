#include <iostream>
using namespace std;

// Utility to print array
void display(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

// Improved selection sort: finds both min & max each pass
void betterSelectionSort(int a[], int n) {
    int left = 0, right = n - 1;

    while (left < right) {

        int minIdx = left;
        int maxIdx = left;

        // find smallest and largest in the current range
        for (int i = left; i <= right; i++) {
            if (a[i] < a[minIdx])
                minIdx = i;

            if (a[i] > a[maxIdx])
                maxIdx = i;
        }

        // move the minimum element to the front
        swap(a[left], a[minIdx]);

        // if max element was at 'left', its position changed
        if (maxIdx == left)
            maxIdx = minIdx;

        // move the maximum element to the end
        swap(a[right], a[maxIdx]);

        display(a, n);  // print after each shrink step

        left++;
        right--;
    }
}

int main() {
    int arr[] = {20, 5, 9, 1, 7, 13, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    betterSelectionSort(arr, n);

    cout << "Final sorted array (Improved Selection): ";
    display(arr, n);

    return 0;
}
