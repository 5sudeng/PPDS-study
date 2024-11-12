"""
<<= (Left Shift Assignment)
>>= (Right Shift Assignment)
|= (Bitwise OR Assignment)
& (Bitwise AND)
"""
class Solution:
    def reverseBits(self, n: int) -> int:
        reversed = 0
        for _ in range(32):
            reversed <<= 1  # Make room for the next bit
            reversed |= n & 1  # Add the least significant bit of n to reversed
            n >>= 1  # Shift n right to get the next bit
        return reversed


def main():
    solution = Solution()

    # Test Case 1
    n1 = int('00000010100101000001111010011100', 2)
    result1 = solution.reverseBits(n1)
    print(f"Test Case 1:")
    print(f"Input: {n1} (binary: {n1:032b})")
    print(f"Output: {result1} (binary: {result1:032b})")

    # Test Case 2
    n2 = int('11111111111111111111111111111101', 2)
    result2 = solution.reverseBits(n2)
    print(f"Test Case 2:")
    print(f"Input: {n2} (binary: {n2:032b})")
    print(f"Output: {result2} (binary: {result2:032b})")

if __name__ == "__main__":
    main()