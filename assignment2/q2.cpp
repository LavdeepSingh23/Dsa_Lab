#include <iostream>
using namespace std;

int main(){
    int arr[7] = {64, 34, 25, 12, 22, 11, 90}; 

    cout << "Orignial array is:" << endl;

    for (int i = 0; i < 7; i++){
        cout << arr[i] << " ";
    }

    for (int i = 0; i < 6; i++){
        int temp = 0;
        for(int j = 0; j < 6 - i; j++){
            if (arr[j+1] < arr[j]){
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }

    cout << endl;
    cout << "Sorted array is:" << endl;

    for (int i = 0; i < 7; i++){
        cout << arr[i] << " ";
    }
    return 0;
}