#include <iostream>
using namespace std;

int arr[100];
int size;

void create(){
    cout << "Enter the size of the array which you want to create:";
    cin >> size;
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }
    cout << endl;
}

void display(){
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insert(){
    int element, position, temp;
    cout << "Enter the element you want to insert in the array:";
    cin >> element;
    cout << "Enter the position at which you want to insert this element:";
    cin >> position;

    for(int i = size; i > position; i--){
        arr[i] = arr[i-1];
    }
    arr[position] = element;
    size++;

    cout << "Element inserted successfuly!" << endl;
}

void Delete(){
    int position;
    cout << "Enter the postion of the element you want to delete:";
    cin >> position;

    for(int i = position; i < size-1; i++){
        arr[i] = arr[i+1];
    }
    size--;
}

void linearSearch(){
    int element;
    int position = -1;
    cout << "Enter the element you want to search for: ";
    cin >> element;
    if(size != 0){    
        for(int i = 0; i < size; i++){
            if (arr[i] == element){
                position = i;
                break;
            }
        }
    }
    
    if(position != -1){
        cout << "Element is present at index " << position << " of the array!" << endl;
    } else {
        cout << "Element not found in the array!" << endl;
    }
}

int main(){
    int option = 0;
    while(option != 6){
    cout << "Enter: \n" << "1 to Create an array\n" << "2 to Display the array\n" << "3 to Insert an element in the array\n" << "4 to Delete an element from the array\n" << "5 to linear search an element in the array\n" << "6 to exit\n";
    cin >> option;
    switch(option){
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            insert();
            break;
        case 4:
            Delete();
            break;
        case 5:
            linearSearch();
            break;
        case 6:
        cout << "Exiting..." << endl;
        break;

        default:
            cout << "Please enter a valid option!";
            break;
        }
    }
    return 0;
}