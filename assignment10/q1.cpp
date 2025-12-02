#include <stdio.h>

int main() {
    int nums[] = {1, 2, 3, 1};
    int n = sizeof(nums) / sizeof(nums[0]);

    int seen[1000] = {0};   // simple hash

    for (int i = 0; i < n; i++) {
        if (seen[nums[i]] == 1) { 
            printf("true");
            return 0;
        }
        seen[nums[i]] = 1;
    }

    printf("false");
    return 0;
}