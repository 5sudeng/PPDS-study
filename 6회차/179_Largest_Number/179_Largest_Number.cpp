#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Function to generate the largest number
class Solution {
public:
    std::string largestNumber(std::vector<int>& nums) {
        // Convert numbers to strings
        std::vector<std::string> nums_str;
        for (int num : nums) {
            nums_str.push_back(std::to_string(num));
        }

        // Sort the strings based on concatenation
        std::sort(nums_str.begin(), nums_str.end(), [](std::string& a, std::string& b) {
            return a + b > b + a;
        });

        // Handle the edge case where the highest number is '0'
        if (nums_str[0] == "0") {
            return "0";
        }

        // Concatenate the numbers to form the largest number
        std::string result;
        for (const std::string& s : nums_str) {
            result += s;
        }

        return result;
    }
};

// Test cases
int main() {
    Solution solution;

    // Test Case 1
    std::vector<int> nums1 = {10, 2};
    std::cout << "Input: [10, 2]" << std::endl;
    std::cout << "Largest Number: " << solution.largestNumber(nums1) << "\n" << std::endl;

    // Test Case 2
    std::vector<int> nums2 = {3, 30, 34, 5, 9};
    std::cout << "Input: [3, 30, 34, 5, 9]" << std::endl;
    std::cout << "Largest Number: " << solution.largestNumber(nums2) << "\n" << std::endl;
    
    return 0;
}