//SELECTION SORT
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;

    // Taking input
    int a[n];
    cout << "Enter elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "Original Array: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    // Selection sort logic
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        // find smallest element in remaining array
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }

        // swap current index with smallest found
        int temp = a[minIndex];
        a[minIndex] = a[i];
        a[i] = temp;
    }

    cout << "Sorted Array (Selection Sort): ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}
//INSERTION SORT
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    int a[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "Initial Array: ";
    for (int x : a) cout << x << " ";
    cout << endl;

    // Insertion sort
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int pos = i - 1;

        while (pos >= 0 && a[pos] > key) {
            a[pos + 1] = a[pos];
            pos--;
        }
        a[pos + 1] = key;

        cout << "After pass " << i << ": ";
        for (int x : a) cout << x << " ";
        cout << endl;
    }

    cout << "Sorted Array (Insertion Sort): ";
    for (int x : a) cout << x << " ";
}
//BUBBLE SORT
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Original Array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    int passes = 0;

    for (int i = 0; i < n - 1; i++) {
        passes++;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }

    cout << "Total passes (outer loop): " << passes << endl;

    cout << "Sorted Array (Bubble Sort): ";
    for (int x : arr) cout << x << " ";
}
//MERGE SORT
#include <iostream>
#include <vector>
using namespace std;

void mergeArr(vector<int> &a, int l, int mid, int r) {
    vector<int> temp;
    int i = l, j = mid + 1;

    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) temp.push_back(a[i++]);
        else temp.push_back(a[j++]);
    }

    while (i <= mid) temp.push_back(a[i++]);
    while (j <= r) temp.push_back(a[j++]);

    for (int k = 0; k < temp.size(); k++) {
        a[l + k] = temp[k];
    }
}

void mergeSort(vector<int> &a, int l, int r) {
    if (l < r) {
        int mid = l + (r - l) / 2;
        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, r);
        mergeArr(a, l, mid, r);
    }
}

int main() {
    vector<int> v = {12, 31, 35, 8, 32, 17};

    mergeSort(v, 0, v.size() - 1);

    cout << "Sorted Array (Merge Sort): ";
    for (int x : v) cout << x << " ";
    cout << endl;
}
//QUICK SORT
#include <iostream>
using namespace std;

void swapVals(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

int partitionArr(int a[], int low, int high) {
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (a[j] <= pivot) {
            i++;
            swapVals(a[i], a[j]);
        }
    }

    swapVals(a[i + 1], a[high]);
    return i + 1;
}

void quickSort(int a[], int low, int high) {
    if (low < high) {
        int pi = partitionArr(a, low, high);

        cout << "After pivot at " << pi << ": ";
        for (int k = low; k <= high; k++) cout << a[k] << " ";
        cout << endl;

        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    int arr[n];
    cout << "Enter values: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Original: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    quickSort(arr, 0, n - 1);

    cout << "Sorted Array (Quick Sort): ";
    for (int x : arr) cout << x << " ";
}