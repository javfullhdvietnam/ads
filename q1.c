#include <stdio.h>

// recursive calculate Pi function 
double calculatePi(int n) {
    if (n == 0) {
        return 4.0; // the 1st term is 4
    }
    // cal the current term then add it to the result of the previous terms
    double term = 4.0 * (n % 2 == 0 ? 1.0 : -1.0) / (2 * n + 1);
    return term + calculatePi(n - 1);
}

// Main function
int main() {
    int nValues[] = {10, 100, 1000, 10000}; // values of n (n>=0)
    for (int i = 0; i < 4; i++) {
        int n = nValues[i];
        double pi = calculatePi(n - 1); // cal Pi with n-1 terms
        printf("n = %d, Pi = %.10f\n", n, pi); // print to screen the result
    }
    return 0;
}


/*
calculate the complexity:
- time complexity:
    +the function makes n recursive calls to calculate n terms of the series.
    +each call performs constant-time calculations (O(1)).
    +total time complexity: O(n).

- space complexity:
    +each recursive call uses stack memory to store the state of the function.
    +the maximum depth of recursion is n (when n = 0, recursion stops).
    +total space complexity: O(n).

=>> So the complexity is O(n)
*/
