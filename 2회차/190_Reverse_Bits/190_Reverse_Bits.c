#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>  // For portable format specifiers

uint32_t reverseBits(uint32_t n) {
    uint32_t reversed = 0;
    for(int i = 0; i < 32; ++i) {
        reversed <<= 1;            // Shift reversed left by 1 bit
        reversed |= n & 1;         // Add the least significant bit of n to reversed
        n >>= 1;                   // Shift n right by 1 bit
    }
    return reversed;
}

void printBinary(uint32_t n) {
    for(int i = 31; i >= 0; --i) {
        printf("%u", (n >> i) & 1);
        if(i % 8 == 0 && i != 0) {
            printf(" ");  // Add space every byte for readability
        }
    }
}

void test_reverse_bits() {
    printf("Test Case 1:\n");
    uint32_t n1 = 0b00000010100101000001111010011100;
    uint32_t expected1 = 0b00111001011110000010100101000000;
    uint32_t result1 = reverseBits(n1);
    printf("Input: %u (binary: ", n1);
    printBinary(n1);
    printf(")\nExpected Output: %u (binary: ", expected1);
    printBinary(expected1);
    printf(")\nActual Output: %u (binary: ", result1);
    printBinary(result1);
    printf(")\nPass: %s\n\n", result1 == expected1 ? "True" : "False");

    printf("Test Case 2:\n");
    uint32_t n2 = 0b11111111111111111111111111111101;
    uint32_t expected2 = 0b10111111111111111111111111111111;
    uint32_t result2 = reverseBits(n2);
    printf("Input: %u (binary: ", n2);
    printBinary(n2);
    printf(")\nExpected Output: %u (binary: ", expected2);
    printBinary(expected2);
    printf(")\nActual Output: %u (binary: ", result2);
    printBinary(result2);
    printf(")\nPass: %s\n\n", result2 == expected2 ? "True" : "False");
}

int main() {
    test_reverse_bits();
    return 0;
}