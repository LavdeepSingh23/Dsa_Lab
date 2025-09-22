#include <iostream>
using namespace std;

int main(){
    int rows, cols;
    int row_sum = 0;
    int col_sum = 0;
    int arr[100][100];

    cout << "Enter the number of rows in the array:";
    cin >> rows;
    cout << "Enter the number of columns in the array:";
    cin >> cols;

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cin >> arr[i][j];
        }
    }

    cout << "The given matrix is: " << endl;

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            row_sum += arr[i][j];           
        }
        cout << "Sum of row " << i+1 << " of the array is " << row_sum << endl; 
        row_sum = 0;
    }

    for(int i = 0; i < cols; i++){
        for(int j = 0; j < rows; j++){
            col_sum += arr[j][i];           
        }
        cout << "Sum of column " << i+1 << " of the array is " << col_sum << endl; 
        col_sum = 0;
    }
    return 0;
}