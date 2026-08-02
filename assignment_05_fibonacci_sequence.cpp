// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 5
// =============================================================================
//
// TASK: Fibonacci Sequence Generator
//
// The Fibonacci sequence is a series of numbers where each number is the sum
// of the two numbers before it:
//
//   0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
//
// Write a C++ program with TWO parts, each implemented as a function.
//
// -----------------------------------------------------------------------------
// PART A — Print the First N Terms
// -----------------------------------------------------------------------------
// - Ask the user how many terms (N) to display.
// - Print the first N numbers of the Fibonacci sequence on one line.
//
// Example:
//   How many terms? 7
//   Fibonacci sequence: 0 1 1 2 3 5 8
//
// -----------------------------------------------------------------------------
// PART B — Check if a Number Belongs to the Sequence
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Determine whether that number is a Fibonacci number.
// - Print an appropriate message.
//
// Example:
//   Enter a number to check: 13
//   13 is a Fibonacci number.
//
//   Enter a number to check: 20
//   20 is NOT a Fibonacci number.
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use a loop (not recursion) to generate the sequence in both parts.
// - N must be a positive integer. If it is not, print an error message.
// - Each part must be implemented in its own function (see scaffold below).
//

//
// =============================================================================
#include <iostream>
using namespace std;

// PART A: Function to generate and print the first N terms of the Fibonacci sequence
void printFibonacci(int n) {
    if (n <= 0) {
        cout << "Error: Number of terms must be greater than 0." << endl;
        return;
    }

    cout << "Fibonacci sequence: ";
    
    long long first = 0, second = 1;

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            cout << first << " ";
        } else if (i == 1) {
            cout << second << " ";
        } else {
            long long next = first + second;
            cout << next << " ";
            first = second;
            second = next;
        }
    }
    cout << endl;
}

// PART B: Function to check if a target number belongs to the Fibonacci sequence
bool isFibonacci(long long num) {
    // Negative numbers are not in the standard Fibonacci sequence
    if (num < 0) {
        return false;
    }

    // Base sequence values
    if (num == 0 || num == 1) {
        return true;
    }

    long long first = 0, second = 1;
    long long next = first + second;

    // Keep generating terms until we reach or exceed the target number
    while (next < num) {
        first = second;
        second = next;
        next = first + second;
    }

    // If the next calculated sequence value matches the number, it's a Fibonacci number
    return (next == num);
}

int main() {
    // -------------------------------------------------------------------------
    // PART A: Print First N Terms
    // -------------------------------------------------------------------------
    cout << "========================================" << endl;
    cout << "   PART A: PRINT FIBONACCI SEQUENCE     " << endl;
    cout << "========================================" << endl;
    
    int n;
    cout << "How many terms? ";
    cin >> n;

    printFibonacci(n);

    // -------------------------------------------------------------------------
    // PART B: Check Fibonacci Number
    // -------------------------------------------------------------------------
    cout << "\n========================================" << endl;
    cout << "  PART B: CHECK FIBONACCI MEMBERSHIP   " << endl;
    cout << "========================================" << endl;

    long long checkNum;
    cout << "Enter a number to check: ";
    cin >> checkNum;

    if (isFibonacci(checkNum)) {
        cout << checkNum << " is a Fibonacci number." << endl;
    } else {
        cout << checkNum << " is NOT a Fibonacci number." << endl;
    }

    return 0;
}
// =============================================================================


