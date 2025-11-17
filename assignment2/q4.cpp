#include <iostream>
#include <cstring>
using namespace std;

// ----------------------------------------------------
// (a) Concatenate one string to another
// ----------------------------------------------------
void concatenateStrings() {
    char s1[100], s2[100];

    cout << "\nEnter first string: ";
    cin >> s1;

    cout << "Enter second string: ";
    cin >> s2;

    int i = 0;
    while (s1[i] != '\0') i++;

    int j = 0;
    while (s2[j] != '\0') {
        s1[i] = s2[j];
        i++; j++;
    }
    s1[i] = '\0';

    cout << "Concatenated string: " << s1 << endl;
}

// ----------------------------------------------------
// (b) Reverse a string
// ----------------------------------------------------
void reverseString() {
    char s[100];
    cout << "\nEnter a string to reverse: ";
    cin >> s;

    int len = 0;
    while (s[len] != '\0') len++;

    int start = 0, end = len - 1;
    char temp;

    while (start < end) {
        temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }

    cout << "Reversed string: " << s << endl;
}

// ----------------------------------------------------
// (c) Delete all vowels from string
// ----------------------------------------------------
void deleteVowels() {
    char s[100];
    cout << "\nEnter a string to remove vowels: ";
    cin >> s;

    char result[100];
    int j = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        if (c!='a' && c!='e' && c!='i' && c!='o' && c!='u' &&
            c!='A' && c!='E' && c!='I' && c!='O' && c!='U') 
        {
            result[j++] = c;
        }
    }
    result[j] = '\0';

    cout << "String without vowels: " << result << endl;
}

// ----------------------------------------------------
// (d) Sort strings alphabetically (Bubble Sort)
// ----------------------------------------------------
void sortStrings() {
    int n;
    cout << "\nHow many strings to sort? ";
    cin >> n;

    char s[20][50];

    cout << "Enter strings:\n";
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (strcmp(s[j], s[j+1]) > 0) {
                char temp[50];
                strcpy(temp, s[j]);
                strcpy(s[j], s[j+1]);
                strcpy(s[j+1], temp);
            }
        }
    }

    cout << "Strings in alphabetical order:\n";
    for (int i = 0; i < n; i++)
        cout << s[i] << endl;
}

// ----------------------------------------------------
// (e) Convert uppercase to lowercase
// ----------------------------------------------------
void upperToLower() {
    char c;
    cout << "\nEnter an uppercase character: ";
    cin >> c;

    if (c >= 'A' && c <= 'Z') {
        c = c + 32;
        cout << "Lowercase: " << c << endl;
    } else {
        cout << "Not an uppercase letter.\n";
    }
}

// ----------------------------------------------------
// MAIN: Calls all programs in order
// ----------------------------------------------------
int main() {

    cout << "===== STRING PROGRAMS (All-in-One) =====\n";

    concatenateStrings();  
    reverseString();       
    deleteVowels();        
    sortStrings();         
    upperToLower();        

    return 0;
}
