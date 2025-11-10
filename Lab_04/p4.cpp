#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

// Add two matrices
vector<vector<int>> addMatrix(vector<vector<int>>& A, vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

// Subtract two matrices
vector<vector<int>> subMatrix(vector<vector<int>>& A, vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

// Strassen multiplication
vector<vector<int>> strassen(vector<vector<int>>& A, vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));

    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }

    int k = n / 2;
    vector<vector<int>> A11(k, vector<int>(k)), A12(k, vector<int>(k)), A21(k, vector<int>(k)), A22(k, vector<int>(k));
    vector<vector<int>> B11(k, vector<int>(k)), B12(k, vector<int>(k)), B21(k, vector<int>(k)), B22(k, vector<int>(k));

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];
            A22[i][j] = A[i + k][j + k];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];
            B22[i][j] = B[i + k][j + k];
        }
    }

    auto M1 = strassen(addMatrix(A11, A22), addMatrix(B11, B22));
    auto M2 = strassen(addMatrix(A21, A22), B11);
    auto M3 = strassen(A11, subMatrix(B12, B22));
    auto M4 = strassen(A22, subMatrix(B21, B11));
    auto M5 = strassen(addMatrix(A11, A12), B22);
    auto M6 = strassen(subMatrix(A21, A11), addMatrix(B11, B12));
    auto M7 = strassen(subMatrix(A12, A22), addMatrix(B21, B22));

    auto C11 = addMatrix(subMatrix(addMatrix(M1, M4), M5), M7);
    auto C12 = addMatrix(M3, M5);
    auto C21 = addMatrix(M2, M4);
    auto C22 = addMatrix(subMatrix(addMatrix(M1, M3), M2), M6);

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            C[i][j] = C11[i][j];
            C[i][j + k] = C12[i][j];
            C[i + k][j] = C21[i][j];
            C[i + k][j + k] = C22[i][j];
        }
    }

    return C;
}

// Pad matrix to next power of 2
vector<vector<int>> padMatrix(vector<vector<int>>& A, int newSize) {
    int oldSize = A.size();
    vector<vector<int>> padded(newSize, vector<int>(newSize, 0));
    for (int i = 0; i < oldSize; i++)
        for (int j = 0; j < oldSize; j++)
            padded[i][j] = A[i][j];
    return padded;
}

// Remove padding
vector<vector<int>> unpadMatrix(vector<vector<int>>& A, int originalSize) {
    vector<vector<int>> result(originalSize, vector<int>(originalSize));
    for (int i = 0; i < originalSize; i++)
        for (int j = 0; j < originalSize; j++)
            result[i][j] = A[i][j];
    return result;
}

int nextPowerOf2(int n) {
    int p = 1;
    while (p < n) p *= 2;
    return p;
}

int main() {
    int n;
    cout << "Enter size of square matrices: ";
    cin >> n;

    vector<vector<int>> N(n, vector<int>(n));
    vector<vector<int>> M(n, vector<int>(n));

    // -------- User input --------
    cout << "Enter matrix N:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> N[i][j];

    cout << "Enter matrix M:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> M[i][j];

    int newSize = nextPowerOf2(n);
    auto Np = padMatrix(N, newSize);
    auto Mp = padMatrix(M, newSize);

    auto start_time = high_resolution_clock::now();
    auto Cp = strassen(Np, Mp);
    auto end_time = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end_time - start_time);

    auto C = unpadMatrix(Cp, n);

    cout << "\nResultant matrix (N x M):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << C[i][j] << " ";
        cout << endl;
    }

    cout << "\nExecution time: " << duration.count() << " microseconds\n";

    return 0;
}
