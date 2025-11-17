#include <iostream>
using namespace std;

struct Term {
    int row;
    int col;
    int val;
};

class Sparse {
public:
    int r, c, n;     // rows, cols, number of non-zero elements
    Term t[50];      // triplet form: (row, col, val)

    Sparse(int rows = 0, int cols = 0, int count = 0) {
        r = rows;
        c = cols;
        n = count;
    }

    // read matrix in triplet form
    void read() {
        cout << "Enter rows, cols and number of non-zero elements: ";
        cin >> r >> c >> n;

        cout << "Enter row col value for each non-zero element:\n";
        for(int i = 0; i < n; i++) {
            cin >> t[i].row >> t[i].col >> t[i].val;
        }
    }

    // display triplet
    void display() {
        cout << "\nTriplet form:\n";
        cout << "Row Col Val\n";
        for(int i = 0; i < n; i++) {
            cout << t[i].row << "   " 
                 << t[i].col << "   " 
                 << t[i].val << endl;
        }
    }

    // -------------------------------------------------------
    // (a) TRANSPOSE of sparse matrix (simple method)
    // -------------------------------------------------------
    Sparse transpose() {
        Sparse trans(c, r, n);

        int k = 0;
        for(int col = 0; col < c; col++) {
            for(int i = 0; i < n; i++) {
                if(t[i].col == col) {
                    trans.t[k].row = t[i].col;
                    trans.t[k].col = t[i].row;
                    trans.t[k].val = t[i].val;
                    k++;
                }
            }
        }
        return trans;
    }

    // -------------------------------------------------------
    // (b) ADDITION of two sparse matrices
    // -------------------------------------------------------
    Sparse add(Sparse s2) {
        Sparse res;

        if(r != s2.r || c != s2.c) {
            cout << "Matrices cannot be added.\n";
            return res;
        }

        res.r = r;
        res.c = c;

        int i = 0, j = 0, k = 0;

        while(i < n && j < s2.n) {
            if(t[i].row < s2.t[j].row ||
               (t[i].row == s2.t[j].row && t[i].col < s2.t[j].col)) {

                res.t[k++] = t[i++];
            }
            else if(s2.t[j].row < t[i].row ||
                   (t[i].row == s2.t[j].row && s2.t[j].col < t[i].col)) {

                res.t[k++] = s2.t[j++];
            }
            else {
                // same position
                int sum = t[i].val + s2.t[j].val;
                if(sum != 0) {
                    res.t[k].row = t[i].row;
                    res.t[k].col = t[i].col;
                    res.t[k].val = sum;
                    k++;
                }
                i++;
                j++;
            }
        }

        while(i < n)  res.t[k++] = t[i++];
        while(j < s2.n) res.t[k++] = s2.t[j++];

        res.n = k;
        return res;
    }

    // -------------------------------------------------------
    // (c) MULTIPLICATION of two sparse matrices
    // -------------------------------------------------------
    Sparse multiply(Sparse s2) {
        Sparse res;

        if(c != s2.r) {
            cout << "Matrices cannot be multiplied.\n";
            return res;
        }

        res.r = r;
        res.c = s2.c;

        // We multiply each non-zero term
        int k = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < s2.n; j++) {
                if(t[i].col == s2.t[j].row) {

                    int rr = t[i].row;
                    int cc = s2.t[j].col;
                    int val = t[i].val * s2.t[j].val;

                    // check if entry already present → accumulate
                    bool found = false;
                    for(int m = 0; m < k; m++) {
                        if(res.t[m].row == rr && res.t[m].col == cc) {
                            res.t[m].val += val;
                            found = true;
                            break;
                        }
                    }

                    if(!found) {
                        res.t[k].row = rr;
                        res.t[k].col = cc;
                        res.t[k].val = val;
                        k++;
                    }
                }
            }
        }

        res.n = k;
        return res;
    }
};

// -------------------------------------------------------
// MAIN
// -------------------------------------------------------
int main() {

    Sparse s1, s2;

    cout << "Enter first sparse matrix:\n";
    s1.read();

    cout << "\nEnter second sparse matrix:\n";
    s2.read();

    cout << "\n--- TRANSPOSE OF FIRST MATRIX ---\n";
    Sparse tr = s1.transpose();
    tr.display();

    cout << "\n--- ADDITION (s1 + s2) ---\n";
    Sparse addRes = s1.add(s2);
    addRes.display();

    cout << "\n--- MULTIPLICATION (s1 * s2) ---\n";
    Sparse mulRes = s1.multiply(s2);
    mulRes.display();

    return 0;
}
