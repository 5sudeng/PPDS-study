#include <stdio.h>

int minimumOneBitOperations(int n) {
    if (n == 0)
        return 0;

    // Find the position of the most significant bit (MSB)
    int k = 0;
    while ((1 << k) <= n)
        k++;
    k--;

    return (1 << (k + 1)) - 1 - minimumOneBitOperations(n ^ (1 << k));
}

// Example usage
int main() {
    int n1 = 3;
    int result1 = minimumOneBitOperations(n1);
    printf("Minimum operations to reduce %d to 0: %d\n", n1, result1); // Output: 2

    int n2 = 6;
    int result2 = minimumOneBitOperations(n2);
    printf("Minimum operations to reduce %d to 0: %d\n", n2, result2); // Output: 4

    return 0;
}