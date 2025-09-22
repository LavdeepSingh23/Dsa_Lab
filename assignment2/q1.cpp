#include <iostream>
using namespace std;

void bubble_sort(int arr[], int size){
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - i - 1; j++ ){
            int temp;
            if (arr[j+1] < arr[j]) {
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int binary_search(int arr[], int size, int element){
    int left = 0;
    int right = size - 1;

    while (left <= right){
        int mid = (left + right) / 2;
        
        if(arr[mid] == element){
            return mid;
        }

        else if(element < arr[mid]){
            right = mid - 1;
        }

        else{
            left = mid + 1;
        }
    }
    return -1;
}

int main(){
    int size, element;
    int arr[100];
    
    cout << "Enter the size of the array: "; 
    cin >> size;

    for(int j = 0; j < size; j++){
        cin >> arr[j];
    }

    bubble_sort(arr,size);

    cout << "Enter the element you want to search: ";
    cin >> element;

    int x = binary_search(arr, size, element);

    if (x == -1){
        cout << "Element not found!";
    }    
    else {
        cout << "Element found at index " << x << "!";
    }

}