// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int MAX = 10;

// Function to read matrix values from the console
void readMatrix(int matrix[MAX][MAX], int rows, int cols, string matrixName) {
    cout << "\n--- Enter elements for Matrix " << matrixName << " (" << rows << "x" << cols << ") ---" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

// Function to print a matrix in tabular format
void printMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(6) << matrix[i][j];
        }
        cout << endl;
    }
}

// PART A: Transpose (M x N -> N x M)
void transposeMatrix(int A[MAX][MAX], int M, int N, int result[MAX][MAX]) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            result[j][i] = A[i][j];
        }
    }
}

// PART B: Addition (M x N)
void addMatrices(int A[MAX][MAX], int B[MAX][MAX], int M, int N, int result[MAX][MAX]) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

// PART C: Multiplication (M x N) * (N x P) -> (M x P)
void multiplyMatrices(int A[MAX][MAX], int B[MAX][MAX], int M, int N, int P, int result[MAX][MAX]) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < P; j++) {
            result[i][j] = 0;
            for (int k = 0; k < N; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int A[MAX][MAX], B[MAX][MAX], result[MAX][MAX];

    // -------------------------------------------------------------------------
    // PART A: Transpose
    // -------------------------------------------------------------------------
    cout << "========================================" << endl;
    cout << "       PART A: MATRIX TRANSPOSE         " << endl;
    cout << "========================================" << endl;
    
    int rA, cA;
    cout << "Enter number of rows: ";
    cin >> rA;
    cout << "Enter number of columns: ";
    cin >> cA;

    if (rA <= 0 || rA > MAX || cA <= 0 || cA > MAX) {
        cout << "Error: Dimensions must be between 1 and " << MAX << "." << endl;
        return 1;
    }

    readMatrix(A, rA, cA, "A");

    cout << "\nOriginal Matrix A:" << endl;
    printMatrix(A, rA, cA);

    transposeMatrix(A, rA, cA, result);

    cout << "\nTransposed Matrix:" << endl;
    printMatrix(result, cA, rA);

    // -------------------------------------------------------------------------
    // PART B: Addition
    // -------------------------------------------------------------------------
    cout << "\n========================================" << endl;
    cout << "       PART B: MATRIX ADDITION          " << endl;
    cout << "========================================" << endl;
    
    int rB, cB;
    cout << "Enter rows for second matrix (must be " << rA << "): ";
    cin >> rB;
    cout << "Enter columns for second matrix (must be " << cA << "): ";
    cin >> cB;

    if (rB != rA || cB != cA) {
        cout << "Error: Matrices must have identical dimensions for addition." << endl;
    } else {
        readMatrix(B, rB, cB, "B");

        addMatrices(A, B, rA, cA, result);

        cout << "\nMatrix A + Matrix B:" << endl;
        printMatrix(result, rA, cA);
    }

    // -------------------------------------------------------------------------
    // PART C: Multiplication
    // -------------------------------------------------------------------------
    cout << "\n========================================" << endl;
    cout << "     PART C: MATRIX MULTIPLICATION      " << endl;
    cout << "========================================" << endl;
    
    int rMultB, cMultB;
    cout << "For A (" << rA << "x" << cA << ") x B, enter B's rows (must be " << cA << "): ";
    cin >> rMultB;
    cout << "Enter B's columns (P): ";
    cin >> cMultB;

    if (rMultB != cA) {
        cout << "Error: Columns in Matrix A (" << cA 
             << ") must equal rows in Matrix B (" << rMultB << ")." << endl;
    } else if (cMultB <= 0 || cMultB > MAX) {
        cout << "Error: Columns must be between 1 and " << MAX << "." << endl;
    } else {
        readMatrix(B, rMultB, cMultB, "B");

        multiplyMatrices(A, B, rA, cA, cMultB, result);

        cout << "\nMatrix A x Matrix B (" << rA << "x" << cMultB << "):" << endl;
        printMatrix(result, rA, cMultB);
    }

    return 0;
}
// =============================================================================


