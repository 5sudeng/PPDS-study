from typing import List


class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        # Convert numbers to strings
        nums_str = list(map(str, nums))

        # Sort the strings based on concatenation
        nums_str.sort(key=lambda x: x * 10, reverse=True)

        # Handle the edge case where the highest number is '0'
        if nums_str[0] == '0':
            return '0'

        # Concatenate the numbers to form the largest number
        return ''.join(nums_str)


# Test cases
if __name__ == "__main__":
    solution = Solution()

    # Test Case 1
    nums1 = [10, 2]
    print(f"Input: {nums1}")
    print(f"Largest Number: {solution.largestNumber(nums1)}\n")  # Output: "210"

    # Test Case 2
    nums2 = [3, 30, 34, 5, 9]
    print(f"Input: {nums2}")
    print(f"Largest Number: {solution.largestNumber(nums2)}\n")  # Output: "9534330"