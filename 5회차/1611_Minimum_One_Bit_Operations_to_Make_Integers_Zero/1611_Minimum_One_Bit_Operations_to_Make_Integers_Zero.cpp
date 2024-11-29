#include <iostream>

class Solution {
public:
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
};

// Example usage
int main() {
    Solution solution;
    int n1 = 3;
    int result1 = solution.minimumOneBitOperations(n1);
    std::cout << "Minimum operations to reduce " << n1 << " to 0: " << result1 << std::endl; // Output: 2

    int n2 = 6;
    int result2 = solution.minimumOneBitOperations(n2);
    std::cout << "Minimum operations to reduce " << n2 << " to 0: " << result2 << std::endl; // Output: 4

    return 0;
}