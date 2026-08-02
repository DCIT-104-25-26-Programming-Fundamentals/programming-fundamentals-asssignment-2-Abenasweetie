// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================
//
// TASK: Array Statistics Calculator
//
// Write a C++ program that reads a collection of numbers from the user
// and computes key statistical values using separate functions.
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLE
// -----------------------------------------------------------------------------
//
//   How many numbers? 5
//   Enter number 1: 4
//   Enter number 2: 7
//   Enter number 3: 2
//   Enter number 4: 9
//   Enter number 5: 1
//
//   Results:
//   Sum:     23
//   Average: 4.6
//   Maximum: 9
//   Minimum: 1
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement each calculation in its own function (see scaffold).
// - You may NOT use any standard library functions like accumulate(), max(),
//   or min(). Implement the logic yourself using loops.
// - N must be a positive integer. If the user enters 0 or a negative number,
//   print an error message and stop.
//

//
// =============================================================================
#include <iostream>
using namespace std;

// Function to calculate the sum of elements
double calculateSum(const double arr[], int size) {
    double sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum;
}

// Function to calculate the average of elements
double calculateAverage(const double arr[], int size) {
    double sum = calculateSum(arr, size);
    return sum / size;
}

// Function to find the maximum element
double findMax(const double arr[], int size) {
    double maxVal = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

// Function to find the minimum element
double findMin(const double arr[], int size) {
    double minVal = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    return minVal;
}

int main() {
    int n;
    cout << "How many numbers? ";
    cin >> n;

    // Validate that N is positive
    if (n <= 0) {
        cout << "Error: Number of elements must be greater than 0." << endl;
        return 1;
    }

    // Dynamically allocate memory for the array
    double* numbers = new double[n];

    // Read input numbers from the user
    for (int i = 0; i < n; ++i) {
        cout << "Enter number " << (i + 1) << ": ";
        cin >> numbers[i];
    }

    // Compute statistical values using functions
    double sum = calculateSum(numbers, n);
    double average = calculateAverage(numbers, n);
    double maxVal = findMax(numbers, n);
    double minVal = findMin(numbers, n);

    // Display results
    cout << "\nResults:" << endl;
    cout << "Sum:     " << sum << endl;
    cout << "Average: " << average << endl;
    cout << "Maximum: " << maxVal << endl;
    cout << "Minimum: " << minVal << endl;

    // Free allocated memory
    delete[] numbers;

    return 0;
}
// =============================================================================

