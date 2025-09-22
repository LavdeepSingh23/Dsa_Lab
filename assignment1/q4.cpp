#include <iostream>
using namespace std;

int main(){
    //(a) To reverse the elements of an array

    // int size;
    // int arr[100];

    // cout << "Enter the size of the array: ";
    // cin >> size;

    // for(int i = 0; i < size; i++){
    //     cin >> arr[i];
    // }

    // cout << "Orginial array: " << endl;

    //  for(int i = 0; i < size; i++){
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    
    // cout << "Reversed array: " << endl;

    // for(int i = size - 1; i >= 0; i--){
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    //(b) To find matrix multiplication
    int rows1, cols1, rows2, cols2;
    int matrix1[100][100], matrix2[100][100], matrix3[100][100];

    cout << "Enter the number of rows for the first matrix:";
    cin >> rows1;
    cout << "Enter the number of columns for the first matrix:";
    cin >> cols1;

    cout << "Enter the elements:";
    for(int i = 0; i < rows1; i++){
        for(int j = 0; j < cols1; j++){
            cin >> matrix1[i][j];
        }
    }

    cout << "Matrix 1 is:" << endl;

    for(int i = 0; i < rows1; i++){
        for(int j = 0; j < cols1; j++){
            cout << matrix1[i][j] << " ";
        }
        cout << endl;
    }


    // cout << "Enter the number of rows for the second matrix:";
    // cin >> rows2;
    // cout << "Enter the number of columns for the second matrix:";
    // cin >> cols2;

    // cout << "Enter the elements:";
    // for(int i = 0; i < rows2; i++){
    //     for(int j = 0; j < cols2; j++){
    //         cin >> matrix2[i][j];
    //     }
    // }
    
    // cout << "Matrix 2 is:" << endl;

    // for(int i = 0; i < rows2; i++){
    //     for(int j = 0; j < cols2; j++){
    //         cout << matrix2[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // if(cols1 != rows2) {
    //     cout << "Matrix Multiplication is not possible!";
    // }

    // else{
    //     for(int i = 0; i < rows1; i++){
    //         for(int j = 0; j < cols2; j++){
    //             matrix3[i][j] = 0;
    //             for(int k = 0; k < cols1; k++){
    //                 matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
    //             }
    //         }
    //     }

    //     cout << "Matrix multiplication is:" << endl;

    //     for(int i = 0; i < rows1; i++){
    //         for(int j = 0; j < cols2; j++){
    //             cout << matrix3[i][j] << " ";
    //         }
    //         cout << endl;
    // }
    // }

    //(c) To find Transpose of a matrix

    cout << "Transpose of Matrix 1 is:" << endl;

    for(int i = 0; i < cols1; i++){
        for(int j = 0; j < rows1; j++){
            cout << matrix1[j][i] << " ";
        }
        cout << endl;
    }

    return 0;
}