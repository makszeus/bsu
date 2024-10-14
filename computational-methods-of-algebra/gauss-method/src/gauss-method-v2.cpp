#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const int MAX_SIZE = 100;

void printMatrix(double matrix[MAX_SIZE][MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            cout << setw(10) << fixed << setprecision(2) << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void swapRows(double matrix[MAX_SIZE][MAX_SIZE], int n, int i, int j) {
    for (int k = 0; k <= n; k++) {
        double temp = matrix[i][k];
        matrix[i][k] = matrix[j][k];
        matrix[j][k] = temp;
    }
}

int findMax(double matrix[MAX_SIZE][MAX_SIZE], int n, int col) {
    int maxRow = col;
    double maxVal = abs(matrix[col][col]);
    for (int i = col + 1; i < n; i++) {
        double val = abs(matrix[i][col]);
        if (val > maxVal) {
            maxRow = i;
            maxVal = val;
        }
    }
    return maxRow;
}

void solveSystem(double matrix[MAX_SIZE][MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        int maxRow = findMax(matrix, n, i);
        if (maxRow != i) {
            swapRows(matrix, n, i, maxRow);
        }
        for (int j = i + 1; j < n; j++) {
            double factor = matrix[j][i] / matrix[i][i];
            for (int k = i; k <= n; k++) {
                matrix[j][k] -= factor * matrix[i][k];
            }
        }
    }
    double x[MAX_SIZE];
    for (int i = n - 1; i >= 0; i--) {
        x[i] = matrix[i][n] / matrix[i][i];
        for (int j = i - 1; j >= 0; j--) {
            matrix[j][n] -= matrix[j][i] * x[i];
            matrix[j][i] = 0;
        }
    }
    cout << "Solution:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "x[" << i << "] = " << fixed << setprecision(2) << x[i] << endl;
    }
}

int main() {
    int n;
    double matrix[MAX_SIZE][MAX_SIZE];
    cout << "Enter the number of equations: ";
    cin >> n;
    cout << "Enter the coefficients of the equations:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> matrix[i][j];
        }
    }
    cout << "Input matrix:" << endl;
    printMatrix(matrix, n);
    solveSystem(matrix, n);
    return 0;
}
