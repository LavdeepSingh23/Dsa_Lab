#include <iostream>
using namespace std;

// -------------------------------------------------------------
// (a) DIAGONAL MATRIX
// Only store a[i][i]   → space = n
// -------------------------------------------------------------
class DiagonalMatrix {
    int n;
    int *A;
public:
    DiagonalMatrix(int n) {
        this->n = n;
        A = new int[n];
        for(int i = 0; i < n; i++) A[i] = 0;
    }

    void set(int i, int j, int val) {
        if(i == j)
            A[i-1] = val;
    }

    int get(int i, int j) {
        if(i == j) return A[i-1];
        return 0;
    }

    void display() {
        cout << "\nDiagonal Matrix:\n";
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }
};


// -------------------------------------------------------------
// (b) TRI-DIAGONAL MATRIX
// Only store values on 3 diagonals → space = 3n - 2
// Position mapping:
// A[i,i] → diagonal0 index i-1
// A[i,i-1] → diagonal1 index i-2
// A[i,i+1] → diagonal2 index i-1
// -------------------------------------------------------------
class TriDiagonalMatrix {
    int n;
    int *A;
public:
    TriDiagonalMatrix(int n) {
        this->n = n;
        A = new int[3*n - 2];
        for(int i = 0; i < 3*n - 2; i++) A[i] = 0;
    }

    void set(int i, int j, int val) {
        if(i == j)
            A[n - 1 + (i - 1)] = val;  // main diagonal
        else if(i == j + 1)
            A[(i - 2)] = val;         // lower diagonal
        else if(j == i + 1)
            A[2*n - 1 + (i - 1)] = val; // upper diagonal
    }

    int get(int i, int j) {
        if(i == j)
            return A[n - 1 + (i - 1)];
        if(i == j + 1)
            return A[i - 2];
        if(j == i + 1)
            return A[2*n - 1 + (i - 1)];
        return 0;
    }

    void display() {
        cout << "\nTri-Diagonal Matrix:\n";
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++)
                cout << get(i, j) << " ";
            cout << endl;
        }
    }
};


// -------------------------------------------------------------
// (c) LOWER TRIANGULAR MATRIX
// Store elements where i >= j
// Total = n(n+1)/2
// Using Row-major mapping: index = i(i-1)/2 + (j-1)
// -------------------------------------------------------------
class LowerTriangularMatrix {
    int n;
    int *A;
public:
    LowerTriangularMatrix(int n) {
        this->n = n;
        A = new int[n*(n+1)/2];
        for(int i = 0; i < n*(n+1)/2; i++) A[i] = 0;
    }

    void set(int i, int j, int val) {
        if(i >= j) {
            int index = (i*(i-1))/2 + (j-1);
            A[index] = val;
        }
    }

    int get(int i, int j) {
        if(i >= j) {
            int index = (i*(i-1))/2 + (j-1);
            return A[index];
        }
        return 0;
    }

    void display() {
        cout << "\nLower Triangular Matrix:\n";
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++)
                cout << get(i, j) << " ";
            cout << endl;
        }
    }
};


// -------------------------------------------------------------
// (d) UPPER TRIANGULAR MATRIX
// Store elements where j >= i
// Total = n(n+1)/2
// Column-major mapping: index = (j*(j-1))/2 + (i-1)
// -------------------------------------------------------------
class UpperTriangularMatrix {
    int n;
    int *A;
public:
    UpperTriangularMatrix(int n) {
        this->n = n;
        A = new int[n*(n+1)/2];
        for(int i = 0; i < n*(n+1)/2; i++) A[i] = 0;
    }

    void set(int i, int j, int val) {
        if(j >= i) {
            int index = (j*(j-1))/2 + (i - 1);
            A[index] = val;
        }
    }

    int get(int i, int j) {
        if(j >= i) {
            int index = (j*(j-1))/2 + (i - 1);
            return A[index];
        }
        return 0;
    }

    void display() {
        cout << "\nUpper Triangular Matrix:\n";
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++)
                cout << get(i, j) << " ";
            cout << endl;
        }
    }
};


// -------------------------------------------------------------
// (e) SYMMETRIC MATRIX
// Store only lower triangle since A[i][j] = A[j][i]
// Same storage as lower triangular: n(n+1)/2
// -------------------------------------------------------------
class SymmetricMatrix {
    int n;
    int *A;
public:
    SymmetricMatrix(int n) {
        this->n = n;
        A = new int[n*(n+1)/2];
        for(int i = 0; i < n*(n+1)/2; i++) A[i] = 0;
    }

    void set(int i, int j, int val) {
        if(i >= j) {
            int index = (i*(i-1))/2 + (j-1);
            A[index] = val;
        } else {  // store symmetric value
            int index = (j*(j-1))/2 + (i-1);
            A[index] = val;
        }
    }

    int get(int i, int j) {
        if(i >= j) {
            int index = (i*(i-1))/2 + (j-1);
            return A[index];
        } else {
            int index = (j*(j-1))/2 + (i-1);
            return A[index];
        }
    }

    void display() {
        cout << "\nSymmetric Matrix:\n";
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++)
                cout << get(i, j) << " ";
            cout << endl;
        }
    }
};


// -------------------------------------------------------------
// MAIN: demonstrates all matrix types
// -------------------------------------------------------------
int main() {

    int n = 4;  // example size

    DiagonalMatrix d(n);
    d.set(1,1,5); d.set(2,2,8); d.set(3,3,9); d.set(4,4,6);
    d.display();

    TriDiagonalMatrix t(n);
    t.set(1,1,4); t.set(2,1,1); t.set(2,2,5); t.set(2,3,2);
    t.set(3,2,7); t.set(3,3,8); t.set(4,3,3); t.set(4,4,9);
    t.display();

    LowerTriangularMatrix l(n);
    l.set(4,1,3); l.set(4,2,5); l.set(4,3,9); l.set(4,4,7);
    l.display();

    UpperTriangularMatrix u(n);
    u.set(1,1,2); u.set(1,2,3); u.set(1,3,4); u.set(1,4,5);
    u.display();

    SymmetricMatrix s(n);
    s.set(1,1,2); s.set(1,4,7); 
    s.set(3,2,9); s.set(3,3,5);
    s.display();

    return 0;
}
