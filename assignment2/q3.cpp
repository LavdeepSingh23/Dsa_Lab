#include <iostream>
using namespace std;

int missing_linear(int arr[], int size){
    for(int i = 0; i < size; i++){
        if (arr[i] != i+1){
            return i+1;
        }
    }
    return size + 1;
}

int missing_binary(int arr[], int size){
    int left = 0;
    int right = size - 1;

    while(left <= right){
        int mid = (left + right) / 2;
        if (arr[mid] == mid + 1){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return left + 1;
}

int main(){
    int arr[100];
    int size;

    cout << "Enter the size of the array: ";
    cin >> size;

    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }

    int linear = missing_linear(arr, size);

    cout << "Missing linear is " << linear <<  endl;

    int binary = missing_binary(arr, size);

    cout << "Missing binary is " << binary << endl;

    return 0;
}