    #include <iostream>
using namespace std;

int main() {
    int nums[] = {2, 3, 2, 4, 3, 2};
    int n = sizeof(nums) / sizeof(nums[0]);

    int freq[1000] = {0}; // frequency array

    // Count occurrences
    for (int i = 0; i < n; i++) {
        freq[nums[i]]++;
    }

    // Display all numbers which appeared
    for (int val = 0; val < 1000; val++) {
        if (freq[val] > 0) {
            cout << val << " -> " << freq[val] << " times" << endl;
        }
    }

    return 0;
}
