#include <iostream>
using namespace std;

int main(){
    int size;
    int arr[100];
    cout << "Enter the size of the Array: ";
    cin >> size;

    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }

    cout << "Orginial array: " << endl;

     for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
    for(int i = 0; i < size; i++){
        int count = 0;
        for(int j = 0; j < size; j++){
            if (arr[j] == arr[i]){
                count++;
                if (count > 1){
                    for(int k = j; k < size - 1; k++){
                        arr[k] = arr[k+1];
                    }
                    size--;
                    j--;
                }
            }
        }
    }

    cout << "Unique element array: " << endl;

     for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}