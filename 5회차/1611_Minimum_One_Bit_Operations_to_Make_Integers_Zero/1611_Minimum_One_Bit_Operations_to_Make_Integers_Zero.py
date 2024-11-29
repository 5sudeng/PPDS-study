class Solution:
    def minimumOneBitOperations(self, n: int) -> int:
        if n == 0:
            return 0
        # Find the position of the most significant bit (MSB)
        k = 0
        while 2**k <= n:
            k += 1
        k -= 1

        return 2**(k+1)-1 - self.minimumOneBitOperations(2**k ^ n)


# Example usage:
if __name__ == "__main__":
    solution = Solution()
    print(solution.minimumOneBitOperations(3))  # Output: 2
    print(solution.minimumOneBitOperations(6))  # Output: 4