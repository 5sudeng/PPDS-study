#include <iostream>
#include <cstdint>
#include <bitset>

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t reversed = 0;
        for(int i = 0; i < 32; ++i) {
            reversed <<= 1;         // Shift reversed left by 1 bit
            reversed |= n & 1;      // Add the least significant bit of n to reversed
            n >>= 1;                // Shift n right by 1 bit
        }
        return reversed;
    }
};

void printBinary(uint32_t n) {
    std::bitset<32> bits(n);
    for(int i = 31; i >= 0; --i) {
        std::cout << bits[i];
        if(i % 8 == 0 && i != 0) {
            std::cout << " ";  // Add space every byte for readability
        }
    }
}

void test_reverse_bits() {
    Solution solution;

    std::cout << "Test Case 1:\n";
    uint32_t n1 = 0b00000010100101000001111010011100;
    uint32_t expected1 = 0b00111001011110000010100101000000;
    uint32_t result1 = solution.reverseBits(n1);
    std::cout << "Input: " << n1 << " (binary: ";
    printBinary(n1);
    std::cout << ")\nExpected Output: " << expected1 << " (binary: ";
    printBinary(expected1);
    std::cout << ")\nActual Output: " << result1 << " (binary: ";
    printBinary(result1);
    std::cout << ")\nPass: " << (result1 == expected1 ? "True" : "False") << "\n\n";

    std::cout << "Test Case 2:\n";
    uint32_t n2 = 0b11111111111111111111111111111101;
    uint32_t expected2 = 0b10111111111111111111111111111111;
    uint32_t result2 = solution.reverseBits(n2);
    std::cout << "Input: " << n2 << " (binary: ";
    printBinary(n2);
    std::cout << ")\nExpected Output: " << expected2 << " (binary: ";
    printBinary(expected2);
    std::cout << ")\nActual Output: " << result2 << " (binary: ";
    printBinary(result2);
    std::cout << ")\nPass: " << (result2 == expected2 ? "True" : "False") << "\n\n";
}

int main() {
    test_reverse_bits();
    return 0;
}