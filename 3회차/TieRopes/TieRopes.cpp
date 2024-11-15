#include <iostream>
#include <vector>

int solution(int K, std::vector<int> &A) {
    int count = 0;            // Number of ropes with length >= K
    int current_length = 0;   // Length of the current rope being formed

    for (size_t i = 0; i < A.size(); ++i) {
        current_length += A[i];   // Tie the current rope with the next one
        if (current_length >= K) {
            count++;              // Found a rope of sufficient length
            current_length = 0;   // Reset to start forming a new rope
        }
    }

    return count;
}

// Example usage:
int main() {
    int K = 4;
    std::vector<int> A = {1, 2, 3, 4, 1, 1, 3};
    int result = solution(K, A);
    std::cout << "The maximum number of ropes of length >= " << K << " is: " << result << std::endl;
    return 0;
}