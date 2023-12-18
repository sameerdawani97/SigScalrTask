#include <stdio.h>

// Created by Sameer Dawani.

// This function is used to calculate the Fibonacci series using recursion with memoization.
int Fibonacci_recursion(int n, int memo[]){
    // we have the base case which is, either if n is 0 or 1, simply return n itself.
    if (n <= 1) {
        return n;
    }

    // if we have not calculated the Fibonacci number in previous iteration, we calculate this by recursion.
    if (memo[n] == -1) {
        memo[n] = Fibonacci_recursion(n-1, memo) + Fibonacci_recursion(n-2, memo);
    }

    // if we have calculated the Fibonacci number before, we get it by memoization.
    return memo[n];

}


int main() {
    int n;
    printf("Enter the value of n: ");

    // check to ensure it is a number.
    if (scanf("%d", &n) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return 1;
    }

    // check to ensure it is a positive number
    if (n < 0) {
        printf("Please enter a non-negative integer.\n");
        return 1;
    }

    // initialization of result array and memo array.
    int result[n];
    int memo[n];


    // Initializing memo array with -1 indicating memoization not started.
    for (int i = 0; i < n; ++i) {
        memo[i] = -1;
    }

    // Calculate Fibonacci sequence using recursion top down and store it in result array.
    for (int i = 0; i < n; ++i) {
        result[i] = Fibonacci_recursion(i, memo);
    }

    // Print the result
    printf("Fibonacci sequence up to %d: \n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");


    return 0;
}

// Time complexity of this program is O(n).


